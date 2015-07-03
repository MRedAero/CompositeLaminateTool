import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate = Extension('_matrix_math',
                    sources=['matrix_math.i',
                             'matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='matrix_math', ext_modules=[laminate])