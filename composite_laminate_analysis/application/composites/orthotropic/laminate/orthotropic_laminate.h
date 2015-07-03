//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_ORTHOTROPICLAMINATE_H
#define CLT_ORTHOTROPICLAMINATE_H

#include "../lamina/orthotropic_lamina.h"
#include "../../utilities/array_2d.h"
#include "../../utilities/basic_array_2d.h"
#include "../../utilities/array_3d.h"
#include <vector>

using namespace std;

typedef struct StressStrain {
    double a11, a22, a12, A1t, A1c, A2t, A2c, A12;
} StressStrain;

typedef BasicArray2D<StressStrain> StressStrain2D;

class PlyStressStrain {
    public:
    PlyStressStrain(void);
    ~PlyStressStrain(void);

    BasicArray2D<StressStrain> *stress;
    BasicArray2D<StressStrain> *strain;
};

class OrthotropicLaminate {

    void calculate_unit_stress(void);

public:

    OrthotropicLaminate(void);
    ~OrthotropicLaminate(void);

    vector<OrthotropicLamina> stackup;

    Array2D<double> *ABDmat, *ABDinv;
    double Exx, Eyy, Gxy, nuxy, nuyx, thickness;

    Array3D<double> *local_ply_strain;
    Array3D<double> *local_ply_stress;

    void calculate_laminate_properties(void);

    void set_number_of_plies(unsigned int);
    OrthotropicLamina *get_ply(unsigned int);
    double get_unit_strain(unsigned int, unsigned int, unsigned int);
    double get_unit_stress(unsigned int, unsigned int, unsigned int);

    PlyStressStrain *apply_loads(Array2D<double> *);

};


#endif //CLT_ORTHOTROPICLAMINATE_H
