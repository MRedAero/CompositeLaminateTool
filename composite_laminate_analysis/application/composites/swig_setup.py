import sys

sys.argv.append('build_ext')
#sys.argv.append('--inplace')
sys.argv.append('--compiler=mingw32')

from distutils.core import setup, Extension

laminate_folder = r'./laminate_orthotropic/'
lamina_folder = laminate_folder + r'lamina_orthotropic/'
material_folder = lamina_folder + r'material_orthotropic/'

material = Extension('_material_orthotropic',
                    sources=[material_folder + 'material_orthotropic.cpp',
                             material_folder + 'material_orthotropic.i',
                             './utilities/matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)

lamina = Extension('_lamina_orthotropic',
                    sources=[lamina_folder + 'lamina_orthotropic.cpp',
                             lamina_folder + 'lamina_orthotropic.i',
                             material_folder + 'material_orthotropic.cpp',
                             './utilities/matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)

laminate = Extension('_laminate_orthotropic',
                    sources=[laminate_folder + 'laminate_orthotropic.i',
                             laminate_folder + 'laminate_orthotropic.cpp',
                             lamina_folder + 'lamina_orthotropic.cpp',
                             material_folder + 'material_orthotropic.cpp',
                             './utilities/matrix_math.cpp'],
                    language='c++',
                    swig_opts=['-c++'],)


setup(name='laminate_orthotropic', ext_modules=[material, lamina, laminate])