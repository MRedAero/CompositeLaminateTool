__author__ = 'Michael Redmond'

from LaminateOrthotropic import LaminateOrthotropic
from LaminaOrthotropic import LaminaOrthotropic
from MaterialOrthotropic import MaterialOrthotropic

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

k = 4
for i in xrange(4):
    print "%f, %f, %f\n", (laminate.get_unit_strain(4, i, 0)*1000000., laminate.get_unit_strain(4, i, 1)*1000000.,
                           laminate.get_unit_strain(4, i, 2)*1000000.)

for i in xrange(4):
    print "%f, %f, %f\n", (laminate.get_unit_stress(4, i, 0), laminate.get_unit_stress(4, i, 1),
                           laminate.get_unit_stress(4, i, 2))
