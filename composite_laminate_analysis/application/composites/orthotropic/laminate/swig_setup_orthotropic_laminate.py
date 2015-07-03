import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate = Extension('_orthotropic_laminate',
                    sources=['orthotropic_laminate.i',
                             'orthotropic_laminate.cpp',
                             '../lamina/orthotropic_lamina.cpp',
                             '../material/orthotropic_material.cpp',
                             '../../utilities/matrix_math.cpp',
                            #'./failure_analysis/orthotropic_analysis.cpp'
                             ],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='orthotropic_laminate', ext_modules=[laminate])