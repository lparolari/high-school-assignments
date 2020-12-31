import logging


def get_log_level(is_verbose: bool) -> int:
    if is_verbose:
        return logging.DEBUG
    else:
        return logging.INFO
