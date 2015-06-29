import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate = Extension('_array_2d',
                    sources=['array_2d.i',
                             'array_2d.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='array_2d', ext_modules=[laminate])