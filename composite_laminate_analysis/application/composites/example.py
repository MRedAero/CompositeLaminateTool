__author__ = 'Michael Redmond'

from orthotropic import (OrthotropicLaminate, OrthotropicMaterial, tsai_wu_analysis)
from utilities import create_2d_array

material = OrthotropicMaterial()
material.E11 = 27000000.
material.E22 = 1500000.
material.nu12 = 0.35
material.G12 = 1100000.
material.F1t = 108000.
material.F1c = -108000.
material.F2t = 9000.
material.F2c = -10500.
material.F12 = 11000.
material.E1t = .004
material.E1c = -.004
material.E2t = .006
material.E2c = -.007
material.E12 = .01

laminate = OrthotropicLaminate()

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

loads = create_2d_array(10, 6)

from random import uniform

for i in xrange(10):
    for j in xrange(6):
        load = uniform(-1., 1.)
        loads.set_data(i, j, load)

ply_loads = laminate.apply_loads(loads)

ply_stress = ply_loads.stress

results = tsai_wu_analysis(ply_stress)

# print strength ratios
for i in xrange(results.rows):
    for j in xrange(results.cols):
        print results.get_data(i, j)

