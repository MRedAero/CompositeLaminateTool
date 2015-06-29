//
// Created by Michael on 6/21/2015.
//

#include <assert.h>
#include <math.h>
#include "material_orthotropic.h"

void MaterialOrthotropic::calculate_elastic_constants(void) {

    assert(this->E11 > 0.);
    assert(this->E22 > 0.);
    assert(this->G12 > 0.);
    assert(this->nu12 > 0.);

    this->nu21 = this->E22*this->nu12/this->E11;

    double m = 1. - this->nu12*this->nu21;

    assert(m > 0.);

    this->C11 = this->E11/m;
    this->C22 = this->E22/m;
    this->C12 = this->nu12*this->C22;
    this->C66 = this->G12;

}