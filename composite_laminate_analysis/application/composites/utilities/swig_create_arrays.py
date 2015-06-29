import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate = Extension('_create_arrays',
                    sources=['create_arrays.i',
                             'create_arrays.cpp',
                             'array_2d.cpp',
                             'array_3d.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='create_arrays', ext_modules=[laminate])