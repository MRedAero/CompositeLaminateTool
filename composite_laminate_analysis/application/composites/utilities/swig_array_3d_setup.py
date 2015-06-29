import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate = Extension('_array_3d',
                    sources=['array_3d.i',
                             'array_3d.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='array_3d', ext_modules=[laminate])