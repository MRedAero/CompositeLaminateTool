
%module orthotropic_laminate

%{
#include "orthotropic_laminate.h"
%}

%pythoncode %{

from ..lamina.orthotropic_lamina import OrthotropicLamina

%}

%feature("docstring") StressStrain "
:type a11: float
:type a22: float
:type a12: float
:type A1t: float
:type A1c: float
:type A2t: float
:type A2c: float
:type A12: float
"

%include "../../utilities/basic_array_2d.h"
%template(StressStrain2D) BasicArray2D<StressStrain>;

%include "../../utilities/array_2d.h"
%template(Double2D) Array2D<double>;

%include "../../utilities/array_3d.h"
%template(Double3D) Array3D<double>;

%feature("docstring") PlyStressStrain "
:type stress: StressStrain2D
:type strain: StressStrain2D
"
%feature("docstring") OrthotropicLaminate "
:type ABDmat: Double2D
:type ABDinv: Double2D
:type Exx: float
:type Eyy: float
:type Gxy: float
:type nuxy: float
:type nuyx: float
:type thickness: float
:type local_ply_strain: Double3D
:type local_ply_stress: Double3D
"

%feature("docstring") OrthotropicLaminate::calculate_laminate_properties "
:returns: Nothing
:rtype: None
"
%feature("docstring") OrthotropicLaminate::set_number_of_plies "
:param size: Number of plies for laminate
:type size: int
:returns: Nothing
:rtype: None
"
%feature("docstring") OrthotropicLaminate::get_ply "
:param i: ply to get (0-based)
:type i: int
:returns: The ply determined by i
:rtype: OrthotropicLamina
"
%feature("docstring") OrthotropicLaminate::get_unit_strain "
:param ply: ply number (0-based)
:type ply: int
:param load: applied load component number (0-5)
:type load: int
:param component: local strain component of ply (0-2)
:type component: int
:returns: strain value
:rtype: float
"
%feature("docstring") OrthotropicLaminate::get_unit_stress "
:param ply: ply number (0-based)
:type ply: int
:param load: applied load component number (0-5)
:type load: int
:param component: local stress component of ply (0-2)
:type component: int
:returns: stress value
:rtype: float
"
%feature("docstring") OrthotropicLaminate::apply_loads "
(Double2D)->PlyStressStrain
:param loads: 2D array of applied loads (loadcases by 6 load components)
:type loads: Double2D
:returns: array of stresses and strains by loadcase and ply number
:rtype: PlyStressStrain
"

%include "orthotropic_laminate.h"

