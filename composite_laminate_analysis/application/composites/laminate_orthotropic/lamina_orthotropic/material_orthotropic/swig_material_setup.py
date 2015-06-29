import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

material_folder = ''

material = Extension('_material_orthotropic',
                    sources=[material_folder + 'material_orthotropic.cpp',
                             material_folder + 'material_orthotropic.i',
                             '../../../utilities/matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='material_orthotropic', ext_modules=[material])