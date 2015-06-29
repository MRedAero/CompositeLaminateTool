
%module array_2d

%{
#include "array_2d.h"
%}

%include "array_2d.h"

%template(array_2d_double) Array2D<double>;
%template(array_2d_int) Array2D<int>;