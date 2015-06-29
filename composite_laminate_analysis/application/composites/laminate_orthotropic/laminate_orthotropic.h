//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_LAMINATEORTHOTROPIC_H
#define CLT_LAMINATEORTHOTROPIC_H

#include "./lamina_orthotropic/lamina_orthotropic.h"
#include "../utilities/array_2d.h"
#include "../utilities/array_3d.h"
#include <vector>

using namespace std;

struct StrainStress_s {
    double data[3];
};

class LaminateOrthotropic {

    void calculate_unit_stress(void);

public:

    LaminateOrthotropic(void);
    ~LaminateOrthotropic(void);

    vector<LaminaOrthotropic> stackup;

    Array2D<double> *ABDmat, *ABDinv;
    double Exx, Eyy, Gxy, nuxy, nuyx, thickness;

    Array3D<double> *local_ply_strain;
    Array3D<double> *local_ply_stress;

    void calculate_laminate_properties(void);

    void set_number_of_plies(unsigned int);
    LaminaOrthotropic *get_ply(unsigned int);
    double get_unit_strain(unsigned int, unsigned int, unsigned int);
    double get_unit_stress(unsigned int, unsigned int, unsigned int);

    Array3D<double> *apply_loads(Array2D<double> *);

};


#endif //CLT_LAMINATEORTHOTROPIC_H
