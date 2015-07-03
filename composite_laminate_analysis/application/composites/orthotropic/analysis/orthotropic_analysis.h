#ifndef ORTHOTROPICANALYSIS_H
#define ORTHOTROPICANALYSIS_H

#include "../laminate/orthotropic_laminate.h"

double tsai_wu_calc(const StressStrain *);

Array2D<double> *tsai_wu_analysis(BasicArray2D<StressStrain> *);

#endif //ORTHOTROPICANALYSIS_H