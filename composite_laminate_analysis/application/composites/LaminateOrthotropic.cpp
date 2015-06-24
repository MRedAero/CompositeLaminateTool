//
// Created by Michael on 6/21/2015.
//

#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "LaminateOrthotropic.h"
#include "matrix_math.h"

void LaminateOrthotropic::calculate_laminate_properties(void) {

    int i;

    if(this->ABDmat) free_2d_array(&this->ABDmat, 6);
    if(this->ABDinv) free_2d_array(&this->ABDinv, 6);

    allocate_2d_array(&this->ABDmat, 6, 6);
    allocate_2d_array(&this->ABDinv, 6, 6);

    this->thickness = 0;
    for(i = 0; i < this->stackup.size(); i++) this->thickness += this->stackup[i].thickness;

    double him1 = -this->thickness/2., hi = him1;

    for(i = 0; i < this->stackup.size(); i++)
    {

        LaminaOrthotropic *lamina = &this->stackup[i];
        lamina->calculate_elastic_constants();

        assert(lamina->thickness > 0.);

        hi += lamina->thickness;

        double hdiff = hi - him1;

        this->ABDmat[0][0] += lamina->Q11*hdiff;
        this->ABDmat[0][1] += lamina->Q12*hdiff;
        this->ABDmat[0][2] += lamina->Q16*hdiff;
        this->ABDmat[1][1] += lamina->Q22*hdiff;
        this->ABDmat[1][2] += lamina->Q26*hdiff;
        this->ABDmat[2][2] += lamina->Q66*hdiff;

        double hdiff2 = hi*hi - him1*him1;

        this->ABDmat[3][0] += lamina->Q11*hdiff2;
        this->ABDmat[3][1] += lamina->Q12*hdiff2;
        this->ABDmat[3][2] += lamina->Q16*hdiff2;
        this->ABDmat[4][1] += lamina->Q22*hdiff2;
        this->ABDmat[4][2] += lamina->Q26*hdiff2;
        this->ABDmat[5][2] += lamina->Q66*hdiff2;

        double hdiff3 = hi*hi*hi - him1*him1*him1;

        this->ABDmat[3][3] += lamina->Q11*hdiff3;
        this->ABDmat[3][4] += lamina->Q12*hdiff3;
        this->ABDmat[3][5] += lamina->Q16*hdiff3;
        this->ABDmat[4][4] += lamina->Q22*hdiff3;
        this->ABDmat[4][5] += lamina->Q26*hdiff3;
        this->ABDmat[5][5] += lamina->Q66*hdiff3;

        him1 = hi;

    }

    assert(this->thickness > 0);

    this->ABDmat[1][0] = this->ABDmat[0][1];
    this->ABDmat[2][0] = this->ABDmat[0][2];
    this->ABDmat[2][1] = this->ABDmat[1][2];

    this->ABDmat[3][0] /= 2.;
    this->ABDmat[3][1] /= 2.;
    this->ABDmat[3][2] /= 2.;
    this->ABDmat[4][1] /= 2.;
    this->ABDmat[4][2] /= 2.;
    this->ABDmat[5][2] /= 2.;

    this->ABDmat[1][3] = this->ABDmat[3][1];
    this->ABDmat[2][3] = this->ABDmat[3][2];
    this->ABDmat[2][4] = this->ABDmat[4][2];

    this->ABDmat[4][0] = this->ABDmat[3][1];
    this->ABDmat[5][0] = this->ABDmat[3][2];
    this->ABDmat[5][1] = this->ABDmat[4][2];

    this->ABDmat[0][3] = this->ABDmat[3][0];
    this->ABDmat[1][3] = this->ABDmat[4][0];
    this->ABDmat[2][3] = this->ABDmat[5][0];
    this->ABDmat[0][4] = this->ABDmat[3][1];
    this->ABDmat[1][4] = this->ABDmat[4][1];
    this->ABDmat[2][4] = this->ABDmat[5][1];
    this->ABDmat[0][5] = this->ABDmat[3][2];
    this->ABDmat[1][5] = this->ABDmat[4][2];
    this->ABDmat[2][5] = this->ABDmat[5][2];

    this->ABDmat[3][3] /= 3.;
    this->ABDmat[3][4] /= 3.;
    this->ABDmat[3][5] /= 3.;
    this->ABDmat[4][4] /= 3.;
    this->ABDmat[4][5] /= 3.;
    this->ABDmat[5][5] /= 3.;

    this->ABDmat[4][3] = this->ABDmat[3][4];
    this->ABDmat[5][3] = this->ABDmat[3][5];
    this->ABDmat[5][4] = this->ABDmat[4][5];

    int successful = inverse_matrix((const double **)this->ABDmat, this->ABDinv, 6);

    // code commented out gives wrong average stiffness, why?  using inverse method instead

    //double tmp = this->ABDmat[0][0]*this->ABDmat[1][1] - this->ABDmat[0][1]*this->ABDmat[0][1];

    //this->Exx = tmp/(this->ABDmat[1][1]*this->thickness);
    //this->Eyy = tmp/(this->ABDmat[0][0]*this->thickness);
    //this->Gxy = this->ABDmat[2][2]/this->thickness;

    //this->nuxy = this->ABDmat[0][1]/this->ABDmat[1][1];
    //this->nuyx = this->ABDmat[0][1]/this->ABDmat[0][0];

    double tmp = 1./this->thickness;

    this->Exx = tmp/this->ABDinv[0][0];
    this->Eyy = tmp/this->ABDinv[1][1];
    this->Gxy = tmp/this->ABDinv[2][2];
    this->nuxy = -this->ABDinv[0][1]/this->ABDinv[0][0];
    this->nuyx = -this->ABDinv[0][1]/this->ABDinv[1][1];

    cout << "Exx = " << this->Exx << "\n";
    cout << "Eyy = " << this->Eyy << "\n";
    cout << "Gxy = " << this->Gxy << "\n";
    cout << "nuxy = " << this->nuxy << "\n";

    if (successful)
    {

        double *unit_loads = NULL;
        unit_loads = (double *)calloc((size_t)6, sizeof(double));

        this->local_ply_strain = (StrainStress_s **)calloc((size_t)6, sizeof(StrainStress_s *));
        this->local_ply_stress = (StrainStress_s **)calloc((size_t)6, sizeof(StrainStress_s *));

        double global_ply_strain[3];
        double to_radians = 0.01745329251994329576923690768489;

        double *global_unit_strains = NULL;

        global_unit_strains = (double *)calloc((size_t)6, sizeof(double));

        for(i = 0; i < 6; i ++)
        {

            memset(&unit_loads[0], 0, sizeof(double)*6);
            unit_loads[i] = 1.;

            multiply_matrix_and_vector((const double **)this->ABDinv,
                                       (const double *)unit_loads,
                                       global_unit_strains, 6, 6);

            double z = -this->thickness/2.;

            this->local_ply_strain[i] = (StrainStress_s *)calloc((size_t)this->stackup.size(), sizeof(StrainStress_s));
            this->local_ply_stress[i] = (StrainStress_s *)calloc((size_t)this->stackup.size(), sizeof(StrainStress_s));

            for(int j = 0; j < this->stackup.size(); j++)
            {

                z += this->stackup[j].thickness/2.;

                global_ply_strain[0] = global_unit_strains[0] + z*global_unit_strains[3];
                global_ply_strain[1] = global_unit_strains[1] + z*global_unit_strains[4];
                global_ply_strain[2] = global_unit_strains[2] + z*global_unit_strains[5];

                double m = cos(to_radians*this->stackup[j].orientation);
                double m2 = m*m;
                double n = sin(to_radians*this->stackup[j].orientation);
                double n2 = n*n;
                double mn = m*n;

                // local ply strain
                double e11 = m2*global_ply_strain[0] + n2*global_ply_strain[1] + m*n*global_ply_strain[2];
                double e22 = n2*global_ply_strain[0] + m2*global_ply_strain[1] - m*n*global_ply_strain[2];
                double e12 = -2.*mn*global_ply_strain[0] + 2.*mn*global_ply_strain[1] + (m2 - n2)*global_ply_strain[2];

                MaterialOrthotropic *material = &this->stackup[j].material;

                // local ply stress
                double f11 = e11*material->C11 + e22*material->C12;
                double f22 = e11*material->C12 + e22*material->C22;
                double f12 = e12*material->C66;

                this->local_ply_strain[i][j].data[0] = e11;
                this->local_ply_strain[i][j].data[1] = e22;
                this->local_ply_strain[i][j].data[2] = e12;

                this->local_ply_stress[i][j].data[0] = f11;
                this->local_ply_stress[i][j].data[1] = f22;
                this->local_ply_stress[i][j].data[2] = f12;

                z += this->stackup[j].thickness/2.;
            }
        }

        free(unit_loads);
        unit_loads = NULL;

        free(global_unit_strains);
        global_unit_strains = NULL;

    } else {

        cout << "Unable to invert laminate ABD matrix!\n";

    }

}

void LaminateOrthotropic::set_number_of_plies(unsigned int size)
{
    this->stackup.resize(size);
}

LaminaOrthotropic *LaminateOrthotropic::get_ply(int i)
{
    return &this->stackup[i];
}

double LaminateOrthotropic::get_unit_strain(int load, int ply, int component)
{
    return this->local_ply_strain[load][ply].data[component];
}

double LaminateOrthotropic::get_unit_stress(int load, int ply, int component)
{
    return this->local_ply_stress[load][ply].data[component];
}