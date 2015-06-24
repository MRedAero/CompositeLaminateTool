//
// Created by Michael on 6/21/2015.
//

#ifndef CLT_LAMINAORTHOTROPIC_H
#define CLT_LAMINAORTHOTROPIC_H

#include "MaterialOrthotropic.h"


class LaminaOrthotropic {
public:
    MaterialOrthotropic material;

    double orientation, thickness;

    // elastic constants
    double Q11, Q22, Q12, Q66, Q16, Q26;

    // methods
    void calculate_elastic_constants(void);

};


#endif //CLT_LAMINAORTHOTROPIC_H
