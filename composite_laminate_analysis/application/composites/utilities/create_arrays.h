#ifndef CREATE_ARRAYS_H
#define CREATE_ARRAYS_H

#include "array_2d.h"
#include "array_3d.h"

Array2D<double> *create_2d_array(unsigned int, unsigned int);
Array3D<double> *create_3d_array(unsigned int, unsigned int, unsigned int);

#endif //CREATE_ARRAYS_H