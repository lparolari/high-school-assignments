#!/usr/bin/env python

import sys
import os
import shutil
import subprocess
import argparse
import logging
from pprint import pprint
import fileinput
from typing import Tuple, List
import dryable
from distutils.dir_util import copy_tree
from build_utils import *


# the make pdf command to fire.
CMD_MAKE_PDF = 'make pdf'


def get_target_dirs(path: str = '.') -> List[str]:
    """
    Returns the result of the `ls` command in path `path` listing
    only non-hidden directories.
    """
    def isdir(f): return os.path.isdir(f)
    def ishidden(f): return f.startswith('.')

    return [f for f in os.listdir(path) if isdir(f) and not ishidden(f)]


def ensure_path(path) -> str:
    if not os.path.exists(path):
        os.makedirs(path)
    return path


@ dryable.Dryable([True, "dry-run"])
def trigger_build(path) -> Tuple[bool, str]:
    logging.info(f'Building "{path}".')
    cmd = f'cd {path}; {CMD_MAKE_PDF}'
    proc = subprocess.Popen(cmd,
                            stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE,
                            shell=True)

    o, e = proc.communicate(timeout=20 * 60)

    e = e.decode('utf-8')
    o = o.decode('utf-8')
    retcode = proc.returncode

    if retcode == 0:
        logging.info(f'Build of "{path}" has done with return code {retcode}.')
        logging.debug(f'Output: {o}')
        return (True, o)
    else:
        logging.error(
            f'Build of "{path}" has failed with return code {retcode}.')
        logging.debug(f'Output: {o}')
        logging.debug(f'Error: {e}')
        return (False, e)


@dryable.Dryable([True, "dry-run"])
def copy_dist(path) -> Tuple[bool, str]:
    dist_folder = '.dist'
    ensure_path(dist_folder)

    logging.info(f'Copying dist from "{path}" to "{dist_folder}".')

    conventional_dirs = ["exercise", "solution"]

    # Note: when *Weak Conventions* are not followed (see README.md) the scripts copies only
    # pdf and cpp files. Instead, when `exercise` and/or `solution` folders are present
    # the script copies only the two directories and their content.

    # TODO: move weak conventions to strict conventions will simplify the code.

    copy_list = []

    for root, dirs, files in os.walk(path):
        for name in dirs:
            if name in conventional_dirs:
                copy_list.append(os.path.join(root, name))
        for name in files:
            if name.endswith(".pdf"):
                copy_list.append(os.path.join(root, name))

    logging.debug(copy_list)

    # Copy pdfs, solution and exercises folder to their folder in `.dist`
    for name in copy_list:
        if os.path.isdir(name):
            copy_tree(name, os.path.join(dist_folder, name))
        else:
            newdir = os.path.join(dist_folder, os.path.dirname(name))
            newfile = os.path.join(dist_folder, name)
            ensure_path(newdir)
            shutil.copy(name, newfile)

    # Copy all pdfs in one directory
    assigmnets_fodler = ".dist-pdf"
    ensure_path(assigmnets_fodler)

    for name in copy_list:
        if not os.path.isdir(name) and name.endswith(".pdf"):
            assigment_name = os.path.dirname(name)
            newfile = os.path.join(assigmnets_fodler, assigment_name + ".pdf")
            shutil.copy(name, newfile)

    logging.info(f'Copied {len(copy_list)} files.')
    return (True, "")


def main(args, loglevel):
    logging.basicConfig(format="%(levelname)s: %(message)s", level=loglevel)

    target_dirs = get_target_dirs()

    print(f'Building directories.')

    failed_no = 0
    build_no = 0

    for d in target_dirs:
        build_no += 1
        (build_ok, out) = trigger_build(d)
        (copy_ok, _) = copy_dist(d)
        if not build_ok:
            failed_no += 1
            # print(out)
            # TODO handle build failures

    print(
        f'Build completed with {build_no-failed_no} success and {failed_no} failed, total {build_no}.')

    return 0 if (failed_no == 0) else 1


# entry point
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="""
            Welcome to the building script for the high school assignments.
            You can build assignments source with a single command.

            (C) Luca Parolari <luca.parolari23@gmail.com>
        """,
        epilog="""
            As an alternative to the commandline, params can be placed
            in a file, one per line, and specified on the commandline
            like '%(prog)s @params.conf'.
        """,
        fromfile_prefix_chars='@')

    parser.add_argument(
        "--dry-run",
        help="Do a trial run with actions performed.",
        action="store_true")

    parser.add_argument(
        "-v",
        "--verbose",
        help="Increase output verbosity.",
        action="store_true")

    args = parser.parse_args()

    dryable.set(args.dry_run)

    log_level = get_log_level(args.verbose)


main(args, log_level or logging.INFO)
