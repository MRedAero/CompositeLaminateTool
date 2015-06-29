//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_MATRIX_MATH_H
#define CLT_MATRIX_MATH_H

#include "array_2d.h"
#include "array_3d.h"

int inverse_matrix(const double **matrix, double **inverse, int);

void multiply_matrix_and_vector(const double **, const double *, double *, int, int);

int inverse_matrix2(Array2D<double> *, Array2D<double> *);
void multiply_matrix_and_vector2(Array2D<double> *, const double *, double *);

void allocate_2d_array(double ***, int, int);
void free_2d_array(double ***, int);
void print_2d_array(double **, int, int);

void allocate_3d_array(double ****, int, int, int);
void free_3d_array(double ****, int, int);

#endif //CLT_MATRIX_MATH_H
