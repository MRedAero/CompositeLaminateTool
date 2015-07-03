import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

lamina = Extension('_orthotropic_lamina',
                   sources=['orthotropic_lamina.cpp',
                            'orthotropic_lamina.i',
                            '../material/orthotropic_material.cpp',
                            '../../utilities/matrix_math.cpp'],
                   language='c++',
                   swig_opts=['-c++'],)

setup(name='orthotropic_lamina', ext_modules=[lamina])