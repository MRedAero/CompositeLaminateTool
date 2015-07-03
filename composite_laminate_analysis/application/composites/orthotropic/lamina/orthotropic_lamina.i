%module orthotropic_lamina
%{
#include "orthotropic_lamina.h"
%}

%pythoncode %{

from ..material.orthotropic_material import OrthotropicMaterial

%}

%feature("docstring") OrthotropicLamina "
:type material: OrthotropicMaterial
:type orientation: float
:type thickness: float
:type Q11: float
:type Q22: float
:type Q12: float
:type Q66: float
:type Q16 float
:type Q26: float
"

%feature("docstring") OrthotropicLamina::calculate_elastic_constants "
:returns: Nothing
:rtype: None
"

%include "orthotropic_lamina.h"