
%module array_3d

%{
#include "array_3d.h"
%}

%include "array_3d.h"

%template(array_3d_double) Array3D<double>;
%template(array_3d_int) Array3D<int>;