//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_ORTHOTROPICLAMINA_H
#define CLT_ORTHOTROPICLAMINA_H

#include "../material/orthotropic_material.h"


class OrthotropicLamina {
public:
    OrthotropicMaterial material;

    double orientation, thickness;

    // elastic constants
    double Q11, Q22, Q12, Q66, Q16, Q26;

    // methods
    void calculate_elastic_constants(void);

};


#endif //CLT_ORTHOTROPICLAMINA_H
