import sys

sys.argv.append('build_ext')
sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate_folder = ''
lamina_folder = laminate_folder + r'lamina_orthotropic/'
material_folder = lamina_folder + r'material_orthotropic/'

laminate = Extension('_laminate_orthotropic',
                    sources=['laminate_orthotropic.i',
                             'laminate_orthotropic.cpp',
                             lamina_folder + 'lamina_orthotropic.cpp',
                             material_folder + 'material_orthotropic.cpp',
                             '../utilities/matrix_math.cpp',
                             '../utilities/array_2d.cpp',
                             '../utilities/array_3d.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='laminate_orthotropic', ext_modules=[laminate])