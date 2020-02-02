#!/usr/bin/env python

import sys
import os
import shutil
import subprocess
import argparse
import logging
from pprint import pprint
import fileinput
from typing import Tuple
import dryable


# the make pdf command to fire.
CMD_MAKE_PDF = 'make pdf'


def get_target_dirs(read_from='list', list=[], path='.'):
    """
    Get target directories from multiple sources like a manual
    list, an input file or from the filesystem directories.

    Parameters
    ----------
    read_from : str, 'infile' or 'ls' or 'list' (default='list')
        Reads target directories from a source.
        Options:
         - 'list', reads from a list of names given with `list`
            attribute (default=[])
         - 'infile', reads from a file name given with `path`
            attribute (required).
         - 'ls', reads from system directories given in `path`
            attribute (default='.').
    """

    if read_from == 'list':
        return list
    if read_from == 'file':
        with open(path, 'r') as f:
            lines = f.readlines()
            lines = [x.strip() for x in lines]
            return lines
    if read_from == 'ls':
        dirs = [f for f in os.listdir(path) if os.path.isdir(
            f) and not f.startswith('.')]
        return dirs


def ensure_path(path) -> str:
    if not os.path.exists(path):
        os.makedirs(path)
    return path


@dryable.Dryable([True, "dry-run"])
def trigger_build(dir) -> Tuple[bool, str]:
    logging.info(f'Building "{dir}".')
    cmd = f'cd {dir}; {CMD_MAKE_PDF}'
    proc = subprocess.Popen(cmd,
                            stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE,
                            shell=True)

    o, e = proc.communicate(timeout=10)

    e = e.decode('ascii')
    o = o.decode('ascii')
    retcode = proc.returncode

    if e == '':
        logging.info(f'Build of "{dir}" has done with return code {retcode}.')
        logging.debug(f'Output: {o}')
        return (True, o)
    else:
        logging.error(
            f'Build of "{dir}" has failed with return code {retcode}.')
        logging.debug(f'Output: {o}')
        logging.debug(f'Error: {e}')
        return (False, e)


@dryable.Dryable([True, "dry-run"])
def copy_dist(dir) -> Tuple[bool, str]:
    dist_folder = '.dist'
    ensure_path(dist_folder)

    logging.info(f'Copying dist from "{dir}" to {dist_folder}.')

    copy_list = []

    for root, _, files in os.walk(dir):
        for file in files:
            if file.endswith(".pdf") or file.endswith(".cpp"):
                copy_list.append(os.path.join(root, file))

    for file in copy_list:
        newdir = os.path.join(dist_folder, dir)
        newfile = os.path.join(dist_folder, dir, os.path.basename(file))
        ensure_path(newdir)
        shutil.copy(file, newfile)

    # TODO: pdf all in one directory with name of parent

    logging.info(f'Copied {len(copy_list)} files.')
    return (True, "")


def main(args, loglevel):
    """dirsdirs
    Main function.
    """
    logging.basicConfig(
        format="%(levelname)s: %(message)s", level=loglevel)

    if args.read_from is None or args.read_from == 'ls':
        target_dirs = get_target_dirs('ls')
    elif args.read_from == 'file':
        target_dirs = get_target_dirs('file', path=args.path)
    elif args.read_from == 'list':
        target_dirs = get_target_dirs('list', list=args.list.split())
    else:
        target_dirs = []

    print(f'Building directories.')

    failed_no = 0
    build_no = 0

    for d in target_dirs:
        build_no += 1
        (build_ok, out) = trigger_build(d)
        (copy_ok, out) = copy_dist(d)
        if not build_ok:
            failed_no += 1
            print(out)
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

    # parser.add_argument(
    #     "argument",
    #     help="pass ARG to the program",
    #     metavar="ARG")
    parser.add_argument(
        "--read-from",
        help="""
            Source from which reading the targets.
            Options are `ls`, `list` and `file`.
            """,
        metavar="source")
    parser.add_argument(
        "--path",
        help="The sources path. (Used with `--read-from` argument with `ls`, `file`).",
        metavar="path")
    parser.add_argument(
        "--list",
        help="The sources list. (Used with `--read-from list`).",
        metavar="list")
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

    # Setup logging
    if args.verbose:
        loglevel = logging.DEBUG
    else:
        loglevel = logging.INFO


main(args, loglevel)
