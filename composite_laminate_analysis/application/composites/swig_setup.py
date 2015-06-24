import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

module1 = Extension('_LaminateOrthotropic',
                    sources=['LaminateOrthotropic.i',
                             'LaminateOrthotropic.cpp',
                             'LaminaOrthotropic.cpp',
                             'MaterialOrthotropic.cpp',
                             'matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)

module2 = Extension('_LaminaOrthotropic',
                    sources=['LaminaOrthotropic.cpp',
                             'LaminaOrthotropic.i',
                             'MaterialOrthotropic.cpp',
                             'matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)

module3 = Extension('_MaterialOrthotropic',
                    sources=['MaterialOrthotropic.cpp',
                             'MaterialOrthotropic.i',
                             'matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)

setup(name='LaminateOrthotropic', ext_modules=[module1, module2, module3])