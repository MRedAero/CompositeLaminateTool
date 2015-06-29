//
// Created by Michael on 6/21/2015.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "matrix_math.h"

using namespace std;

int inverse_matrix(const double **matrix, double **inverse, int n)
{
    bool flag = true;
    int i, j, k, ret_val = 1;
    double m;
    double **augmatrix = NULL;

    allocate_2d_array(&augmatrix, n, 2*n);

    // Augment input matrix with an identity matrix
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            augmatrix[i-1][j-1] = matrix[i-1][j-1];
        }
        augmatrix[i-1][i-1+n] = 1.;
    }

    // Reduce augmented matrix to upper triangular form
    for(k = 1; k <= n-1; k++)
    {
        if(augmatrix[k-1][k-1] == 0.)
        {
            flag = false;
            for(i = k+1; i <=n; i++)
            {
                if(augmatrix[i-1][k-1] != 0.)
                {
                    for(j = 1; j <= 2*n; j++)
                    {
                        augmatrix[k-1][j-1] += augmatrix[i-1][j-1];
                    }
                    flag = true;
                    break;
                }
                if (!flag)
                {
                    printf("Matrix is non-invertible due to augmatrix[%d][%d] == 0 and augumatrix[%d][%d] == 0.", k-1, k-1, i-1, k-1);
                    ret_val = -1;
                    goto exit_function;
                }
            }
        }
        for(j = k+1; j <= n; j++)
        {
            m = augmatrix[j-1][k-1]/augmatrix[k-1][k-1];
            for(i = k; i <= 2*n; i++) augmatrix[j-1][i-1] -= m*augmatrix[k-1][i-1];
        }
    }

    // Test for invertability
    for(i = 1; i <= n; i++)
    {
        if(augmatrix[i-1][i-1] == 0.){
            printf("Matrix is non-invertible due to augmatrix[%d][%d] == 0.", i-1, i-1);
            ret_val = -2;
            goto exit_function;
        }
    }

    // Make diagonal elements as 1
    for(i = 1; i <= n; i++)
    {
        m = augmatrix[i-1][i-1];
        for(j = i; j <= 2*n; j++) augmatrix[i-1][j-1] /= m;
    }

    // Reduced right side half of augmented matrix to identity matrix
    for(k = n-1; k >= 1; k--)
    {
        for(i = 1; i <= k; i++)
        {
            m = augmatrix[i-1][k];
            for(j = k; j <= 2*n; j++) augmatrix[i-1][j-1] -= m*augmatrix[k][j-1];
        }
    }

    // store answer
    for (i = 1; i <= n; i++) for(j = 1; j <= n; j++) inverse[i-1][j-1] = augmatrix[i-1][j-1+n];

    exit_function:
    free_2d_array(&augmatrix, n);

    return ret_val;

}

int inverse_matrix2(Array2D<double> *matrix, Array2D<double> *inverse)
{
    bool flag = true;
    unsigned int i, j, k;
    int ret_val = 1;
    double m;

    unsigned int n = matrix->rows;

    Array2D<double> *augmatrix = new Array2D<double>(n, 2*n);

    // Augment input matrix with an identity matrix
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            augmatrix->set_data(i-1, j-1, matrix->get_data(i-1, j-1));
        }
        augmatrix->set_data(i-1, i-1+n, 1.);
    }

    // Reduce augmented matrix to upper triangular form
    for(k = 1; k <= n-1; k++)
    {
        if(augmatrix->get_data(k-1, k-1) == 0.)
        {
            flag = false;
            for(i = k+1; i <=n; i++)
            {
                if(augmatrix->get_data(i-1, k-1) != 0.)
                {
                    for(j = 1; j <= 2*n; j++)
                    {
                        augmatrix->increment_data(k-1, j-1, augmatrix->get_data(i-1, j-1));
                    }
                    flag = true;
                    break;
                }
                if (!flag)
                {
                    printf("Matrix is non-invertible due to augmatrix[%d][%d] == 0 and augumatrix[%d][%d] == 0.\n", k-1, k-1, i-1, k-1);
                    ret_val = -1;
                    goto exit_function;
                }
            }
        }
        for(j = k+1; j <= n; j++)
        {
            m = augmatrix->get_data(j-1, k-1)/augmatrix->get_data(k-1, k-1);
            for(i = k; i <= 2*n; i++) augmatrix->increment_data(j-1, i-1, -m*augmatrix->get_data(k-1, i-1));
        }
    }

    // Test for invertability
    for(i = 1; i <= n; i++)
    {
        if(augmatrix->get_data(i-1, i-1) == 0.){
            printf("Matrix is non-invertible due to augmatrix[%d][%d] == 0.\n", i-1, i-1);
            ret_val = -2;
            goto exit_function;
        }
    }

    // Make diagonal elements as 1
    for(i = 1; i <= n; i++)
    {
        m = augmatrix->get_data(i-1, i-1);
        for(j = i; j <= 2*n; j++) augmatrix->divide_data(i-1, j-1, m);
    }

    // Reduced right side half of augmented matrix to identity matrix
    for(k = n-1; k >= 1; k--)
    {
        for(i = 1; i <= k; i++)
        {
            m = augmatrix->get_data(i-1, k);
            for(j = k; j <= 2*n; j++) augmatrix->increment_data(i-1, j-1, -m*augmatrix->get_data(k, j-1));
        }
    }

    // store answer
    for (i = 1; i <= n; i++) for(j = 1; j <= n; j++) inverse->set_data(i-1, j-1, augmatrix->get_data(i-1, j-1+n));

    exit_function:
    delete augmatrix;

    return ret_val;

}

void multiply_matrix_and_vector(const double **m, const double *v, double *res, int rows, int cols)
{
    int i, j;

    memset(res, 0, cols*sizeof(double));

    for(i = 0; i < rows; i++) for(j = 0; j < cols; j++) res[i] += m[i][j]*v[j];

}

void multiply_matrix_and_vector2(Array2D<double> *m, const double *v, double *res)
{
    unsigned int i, j;

    memset(res, 0, m->cols*sizeof(double));

    for(i = 0; i < m->rows; i++) for(j = 0; j < m->cols; j++) res[i] += m->get_data(i, j)*v[j];

}

void allocate_2d_array(double ***arr, int rows, int cols)
{
    int i;

    *arr = (double **)calloc((size_t)rows, sizeof(double *));

    for(i = 0; i < rows; i++) (*arr)[i] = (double *)calloc((size_t)cols, sizeof(double));
}

void free_2d_array(double ***arr, int rows)
{
    int i;

    for(i = 0; i < rows; i++)
    {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }

    free(*arr);
    *arr = NULL;

}

void print_2d_array(double **arr, int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++) cout << arr[i][j] << ",";
        cout << "\n";
    }
}

void allocate_3d_array(double ****arr, int i1, int i2, int i3)
{
    int i, j;

    *arr = (double ***)calloc((size_t)i1, sizeof(double **));

    for(i = 0; i < i1; i++)
    {
        (*arr)[i] = (double **)calloc((size_t)i2, sizeof(double *));

        for(j = 0; j < i2; j++)
        {
            (*arr)[i][j] = (double *)calloc((size_t)i3, sizeof(double));
        }
    }
}

void free_3d_array(double ****arr, int i1, int i2)
{
    int i, j;

    for(i = 0; i < i1; i++)
    {
        for(j = 0; j < i2; j++)
        {
            free((*arr)[i][j]);
            (*arr)[i][j] = NULL;
        }

        free((*arr)[i]);
        (*arr)[i] = NULL;
    }

    free(*arr);
    *arr = NULL;
}
