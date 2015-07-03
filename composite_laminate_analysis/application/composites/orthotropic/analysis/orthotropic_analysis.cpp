#include "orthotropic_analysis.h"
#include <math.h>

#include <stdio.h>

double tsai_wu_calc(const StressStrain *p)
{
    double f1, f11, f2, f22, f66, f12;

    f1 = 1./p->A1t - 1./p->A1c;
    f11 = 1./(p->A1t*p->A1c);

    f2 = 1./p->A2t - 1./p->A2c;
    f22 = 1./(p->A2t*p->A2c);

    f66 = 1./(p->A12*p->A12);

    f12 = -0.5/sqrt(p->A1t*p->A1c*p->A2t*p->A2c);

    double a, b, c;

    a = f11*p->a11*p->a11 + f22*p->a22*p->a22 + f66*p->a12*p->a12 + 2.*f12*p->a11*p->a22;
    b = f1*p->a11 + f2*p->a22;
    c = -1.;

    return (-b + sqrt(b*b - 4.*a*c))/(2.*a);

}

Array2D<double> *tsai_wu_analysis(BasicArray2D<StressStrain> *ply_loads)
{
    unsigned int i;

    Array2D<double> *results = new Array2D<double>(ply_loads->rows, ply_loads->cols);
    double *results_data = results->data;

    const StressStrain *data = (const StressStrain *)ply_loads->data;

    for(i = 0; i < ply_loads->rows*ply_loads->cols; i++)
    {
        results_data[i] = tsai_wu_calc((const StressStrain *)&data[i]);
    }

    return results;
}

