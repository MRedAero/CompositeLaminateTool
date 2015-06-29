#include "create_arrays.h"

Array2D<double> *create_2d_array(unsigned int size_i1, unsigned int size_i2)
{
    return new Array2D<double>(size_i1, size_i2);
}


Array3D<double> *create_3d_array(unsigned int size_i1, unsigned int size_i2, unsigned int size_i3)
{
    return new Array3D<double>(size_i1, size_i2, size_i3);
}