%module orthotropic_material
%{
#include "orthotropic_material.h"
%}

%feature("docstring") OrthotropicMaterial "
:type material_name: str
:type material_id: int
:type material_type: str
:type material_product: str
:type env_condition: str
:type application: str
:type E11: float
:type E22: float
:type G12: float
:type nu12: float
:type nu21: float
:type nu32: float
:type E1t: float
:type E1c: float
:type E2t: float
:type E2c: float
:type E12: float
:type E3t: float
:type E3c: float
:type E23: float
:type F1t: float
:type F1c: float
:type F2t: float
:type F2c: float
:type F12: float
:type F3t: float
:type F3c: float
:type F23: float
:type C11: float
:type C22: float
:type C12: float
:type C66: float
"

%feature("docstring") OrthotropicMaterial::calculate_elastic_constants "
:returns: Nothing
:rtype: None
"

%include "orthotropic_material.h"
