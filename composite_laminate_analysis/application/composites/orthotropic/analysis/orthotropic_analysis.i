%module orthotropic_analysis
%{
#include "orthotropic_analysis.h"
%}

%pythoncode %{

from ..laminate.orthotropic_laminate import (OrthotropicLaminate, PlyStressStrain,
StressStrain, Double2D, StressStrain2D)

%}

%feature("docstring") tsai_wu_analysis "
:param ply_loads: local stress/strain per loadcase and per ply
:type ply_loads: StressStrain2D
:returns: 2D Array of Strength Ratios
:rtype: Double2D
"

%include "orthotropic_analysis.h"