import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

material_folder = ''

material = Extension('_orthotropic_material',
                    sources=['orthotropic_material.cpp',
                             'orthotropic_material.i',
                             '../../utilities/matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='orthotropic_material', ext_modules=[material])