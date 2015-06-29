import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

lamina = Extension('_lamina_orthotropic',
                   sources=['lamina_orthotropic.cpp',
                            'lamina_orthotropic.i',
                            './material_orthotropic/material_orthotropic.cpp',
                            '../../utilities/matrix_math.cpp'],
                   language='c++',
                   swig_opts=['-c++'],)

setup(name='lamina_orthotropic', ext_modules=[lamina])