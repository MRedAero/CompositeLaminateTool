__author__ = 'Michael Redmond'

from laminate_orthotropic import (LaminateOrthotropic, MaterialOrthotropic)
from utilities import (create_3d_array, create_2d_array)

material = MaterialOrthotropic()
material.E11 = 27000000.
material.E22 = 1500000.
material.nu12 = 0.35
material.G12 = 1100000.

laminate = LaminateOrthotropic()

laminate.set_number_of_plies(4)

ply = laminate.get_ply(0)
ply.material = material
ply.thickness = 0.008
ply.orientation = 0.

ply = laminate.get_ply(1)
ply.material = material
ply.thickness = 0.008
ply.orientation = 45.

ply = laminate.get_ply(2)
ply.material = material
ply.thickness = 0.008
ply.orientation = -45.

ply = laminate.get_ply(3)
ply.material = material
ply.thickness = 0.008
ply.orientation = 90.

laminate.calculate_laminate_properties()

print laminate.Exx
print laminate.Eyy
print laminate.Gxy
print laminate.nuxy
print laminate.nuyx

if 1:

    k = 4
    for i in xrange(4):
        print "%20f %20f %20f" % (laminate.get_unit_strain(i, 4, 0)*1000000., laminate.get_unit_strain(i, 4, 1)*1000000.,
                               laminate.get_unit_strain(i, 4, 2)*1000000.)

    for i in xrange(4):
        print "%20f %20f %20f" % (laminate.get_unit_stress(i, 4, 0), laminate.get_unit_stress(i, 4, 1),
                               laminate.get_unit_stress(i, 4, 2))

loads = create_2d_array(100, 6)

from random import uniform

for i in xrange(100):
    for j in xrange(6):
        loads.set_data(i, j, uniform(-100., 100.))

results = laminate.apply_loads(loads)

for i in xrange(results.size_i1):
    for j in xrange(results.size_i2):
        print "%20f %20f %20f" % (results.get_data(i, j, 0), results.get_data(i, j, 1), results.get_data(i, j, 2))
