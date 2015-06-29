//
// Created by Michael on 6/21/2015.
//

#include <math.h>
#include <stdio.h>
#include "lamina_orthotropic.h"

void LaminaOrthotropic::calculate_elastic_constants(void) {

    this->material.calculate_elastic_constants();

    double to_radians = 0.01745329251994329576923690768489;

    double c = cos(this->orientation*to_radians), s = sin(this->orientation*to_radians);
    double c2 = c*c, c3 = c*c*c, c4 = c*c*c*c;
    double s2 = s*s, s3 = s*s*s, s4 = s*s*s*s;

    double C11 = this->material.C11, C12 = this->material.C12, C22 = this->material.C22, C66 = this->material.C66;

    this->Q11 = C11*c4 + 2.*(C12 + 2.*C66)*s2*c2 + C22*s4;
    this->Q22 = C11*s4 + 2.*(C12 + 2.*C66)*s2*c2 + C22*c4;
    this->Q12 = (C11 + C22 - 4.*C66)*s2*c2 + C12*(s4 + c4);
    this->Q66 = (C11 + C22 - 2.*C12 - 2.*C66)*s2*c2 + C66*(s4 + c4);
    this->Q16 = (C11 - C12 - 2.*C66)*s*c3 + (C12 - C22 + 2.*C66)*s3*c;
    this->Q26 = (C11 - C12 - 2.*C66)*s3*c + (C12 - C22 + 2.*C66)*s*c3;

}
