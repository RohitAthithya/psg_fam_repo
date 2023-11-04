from os.path import exists, isdir, isfile, basename, dirname, getsize, join
from os.path import islink
from os import walk
from pathlib import Path
from datetime import datetime
from re import sub as re_sub

"""The Zen of Python, by Tim Peters

    Beautiful is better than ugly.
    Explicit is better than implicit.
    Simple is better than complex.
    Complex is better than complicated.
    Flat is better than nested.
    Sparse is better than dense.
    Readability counts.
    Special cases aren't special enough to break the rules.
    Although practicality beats purity.
    Errors should never pass silently.
    Unless explicitly silenced.
    In the face of ambiguity, refuse the temptation to guess.
    There should be one-- and preferably only one --obvious way to do it.
    Although that way may not be obvious at first unless you're Dutch.
    Now is better than never.
    Although never is often better than *right* now.
    If the implementation is hard to explain, it's a bad idea.
    If the implementation is easy to explain, it may be a good idea.
    Namespaces are one honking great idea -- let's do more of those!

"""


def todays_date():
    return str(datetime.now().strftime("%d_%m_%y"))

def remove_whitespaces(in_string:str):
    pattern = "\s+"
    cleaned_string = re_sub(pattern, '', in_string)
    return cleaned_string

def path_exists(path:Path|str) -> bool:
    """Check if the given path exists or not

    Args:
        Path | str: Full path of folder/file

    Returns:
        bool: True if exists else False
    """
    return exists(path)

def folder_exists(package_folder_path:Path|str) -> bool:
    """Check if given path is a folder or not

    Args:
        package_folder_path (str): Full path - ideally a Folder's path

    Returns:
        bool: True if exists else False
    """
    return isdir(package_folder_path)

def file_exists(file_path:Path|str) -> bool:
    """Check if given path is a regular file or not

    Args:
        file_path (str): Full path - ideally a File's path

    Returns:
        -> tuple[bool, str]:    If given path is correct :
                                    (True, "File exists")
                                If given path is not correct :
                                    f"The File '{file_path} does not exist'")
    """
    return isfile(file_path)

def folder_name_from_path(folder_absolute_path:Path|str) -> str:
    """Return the folder name of the given path

    Args:
        input_path (str): Absolute valid path of the folder/file

    Returns:
        str: Folder name
    """
    return str(basename(folder_absolute_path))

def parent_path(input_path:Path|str, choice:int = 0) -> str:
    """Returns the given path's immediate parent path

    Args:
        input_path (str): Absolute valid path of a folder/file

    Returns:
        Choice == 0 => str: parent path as string
        Choice != 0 => Path: parent path as Path Object
    """
    if choice != 0:
        return Path(dirname(input_path))
    return str(dirname(input_path))

def folder_is_empty(input_path:Path|str):
    """If folder empty raise an exception

    Args:
        input_path (str): _description_

    Returns:
        bool: True if the Folder is Empty (No files within it) else False
    """
    if getsize(input_path) <= 0:
        return True
    return False

def get_size_of_folder_in_bytes(start_path:Path|str = '.') -> int[bytes]:
    """Return size of the folder (in Bytes) as in properties of it

    Args:
        start_path (Path|str, optional): _description_. Defaults to '.' (Considers the
        working directory, where this code piece is placed)

    Returns:
        int[bytes]: size of the given folder in bytes reprensented decimally (base = 10)
    """
    total_size = 0
    for dirpath, dirnames, filenames in walk(start_path):
        for f in filenames:
            fp = join(dirpath, f)
            # skip if it is symbolic link
            if not islink(fp):
                total_size += getsize(fp)
    return total_size

