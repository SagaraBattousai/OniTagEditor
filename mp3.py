from ctypes import *
import sys
import os

root_dir = os.path.dirname(os.path.abspath(__file__))

tag_lib = cdll.Mp3TagEditor #LoadLibrary(os.path.join(root_dir, "Mp3TagEditor.dll"))


print(tag_lib.getTagHeader)

