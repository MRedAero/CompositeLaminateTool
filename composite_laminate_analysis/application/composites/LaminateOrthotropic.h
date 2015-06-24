//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_LAMINATEORTHOTROPIC_H
#define CLT_LAMINATEORTHOTROPIC_H

#include "LaminaOrthotropic.h"
#include <vector>

using namespace std;

struct StrainStress_s {
    double data[3];
};

class LaminateOrthotropic {
public:

    vector<LaminaOrthotropic> stackup;

    double **ABDmat, **ABDinv;
    double Exx, Eyy, Gxy, nuxy, nuyx, thickness;
    StrainStress_s **local_ply_strain;
    StrainStress_s **local_ply_stress;

    void calculate_laminate_properties(void);
    void set_number_of_plies(unsigned int );
    LaminaOrthotropic *get_ply(int);
    double get_unit_strain(int, int, int);
    double get_unit_stress(int, int, int);

};


#endif //CLT_LAMINATEORTHOTROPIC_H
