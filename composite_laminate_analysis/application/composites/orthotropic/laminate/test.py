__author__ = 'Michael Redmond'

import orthotropic_laminate

lam = orthotropic_laminate.OrthotropicLaminate()

tmp = lam.local_ply_strain


from ..analysis import orthotropic_analysis
