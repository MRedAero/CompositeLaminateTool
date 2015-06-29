
%module create_arrays

%{
#include "create_arrays.h"
%}

%include "create_arrays.h"
%include "array_2d.h"
%include "array_3d.h"

%template(array_2d_double) Array2D<double>;
%template(array_2d_int) Array2D<int>;

%template(array_3d_double) Array3D<double>;
%template(array_3d_int) Array3D<int>;