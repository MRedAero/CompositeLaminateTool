import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

lamina = Extension('_orthotropic_analysis',
                   sources=['orthotropic_analysis.cpp',
                            'orthotropic_analysis.i',
                            '../laminate/orthotropic_laminate.cpp',
                            '../lamina/orthotropic_lamina.cpp',
                            '../material/orthotropic_material.cpp',
                            '../../utilities/matrix_math.cpp'],
                   language='c++',
                   swig_opts=['-c++'],)

setup(name='orthotropic_analysis', ext_modules=[lamina])