//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_ORTHOTROPICMATERIAL_H
#define CLT_ORTHOTROPICMATERIAL_H

#include <string>

using namespace std;


class OrthotropicMaterial {
public:
    // descriptors
    string material_name;
    int material_id;
    string material_type;
    string material_product;
    string env_condition;
    string application;

    // properties
    double E11, E22, G12, nu12, nu21, nu32;

    // strain allowables
    double E1t, E1c, E2t, E2c, E12, E3t, E3c, E23;

    // stress allowables
    double F1t, F1c, F2t, F2c, F12, F3t, F3c, F23;

    // material properties
    double C11, C22, C12, C66;

    // methods
    void calculate_elastic_constants(void);

};


#endif //CLT_ORTHOTROPICMATERIAL_H
