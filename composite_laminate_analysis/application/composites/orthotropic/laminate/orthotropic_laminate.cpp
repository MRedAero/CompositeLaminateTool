//
// Created by Michael on 6/21/2015.
//

#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "orthotropic_laminate.h"
#include "../../utilities/matrix_math.h"

PlyStressStrain::PlyStressStrain(void)
{
    this->stress = new BasicArray2D<StressStrain>(1, 1);
    this->strain = new BasicArray2D<StressStrain>(1, 1);
}

PlyStressStrain::~PlyStressStrain(void)
{
    delete this->stress;
    delete this->strain;
}

OrthotropicLaminate::OrthotropicLaminate(void)
{
    this->ABDmat = new Array2D<double>(6, 6);
    this->ABDinv = new Array2D<double>(6, 6);
    this->local_ply_strain = new Array3D<double>(1, 6, 3);
    this->local_ply_stress = new Array3D<double>(1, 6, 3);
}

OrthotropicLaminate::~OrthotropicLaminate(void)
{
    delete this->ABDmat;
    delete this->ABDinv;
    delete this->local_ply_strain;
    delete this->local_ply_stress;
}

void OrthotropicLaminate::calculate_laminate_properties(void) {

    unsigned int i;

    this->ABDmat->init(6, 6);
    this->ABDinv->init(6, 6);

    this->thickness = 0;
    for(i = 0; i < this->stackup.size(); i++) this->thickness += this->stackup[i].thickness;

    double him1 = -this->thickness/2., hi = him1;

    for(i = 0; i < this->stackup.size(); i++)
    {

        OrthotropicLamina *lamina = &this->stackup[i];
        lamina->calculate_elastic_constants();

        assert(lamina->thickness > 0.);

        hi += lamina->thickness;

        double hdiff = hi - him1;

        this->ABDmat->increment_data(0, 0, lamina->Q11*hdiff);
        this->ABDmat->increment_data(0, 1, lamina->Q12*hdiff);
        this->ABDmat->increment_data(0, 2, lamina->Q16*hdiff);
        this->ABDmat->increment_data(1, 1, lamina->Q22*hdiff);
        this->ABDmat->increment_data(1, 2, lamina->Q26*hdiff);
        this->ABDmat->increment_data(2, 2, lamina->Q66*hdiff);

        double hdiff2 = hi*hi - him1*him1;

        this->ABDmat->increment_data(3, 0, lamina->Q11*hdiff2);
        this->ABDmat->increment_data(3, 1, lamina->Q12*hdiff2);
        this->ABDmat->increment_data(3, 2, lamina->Q16*hdiff2);
        this->ABDmat->increment_data(4, 1, lamina->Q22*hdiff2);
        this->ABDmat->increment_data(4, 2, lamina->Q26*hdiff2);
        this->ABDmat->increment_data(5, 2, lamina->Q66*hdiff2);

        double hdiff3 = hi*hi*hi - him1*him1*him1;

        this->ABDmat->increment_data(3, 3, lamina->Q11*hdiff3);
        this->ABDmat->increment_data(3, 4, lamina->Q12*hdiff3);
        this->ABDmat->increment_data(3, 5, lamina->Q16*hdiff3);
        this->ABDmat->increment_data(4, 4, lamina->Q22*hdiff3);
        this->ABDmat->increment_data(4, 5, lamina->Q26*hdiff3);
        this->ABDmat->increment_data(5, 5, lamina->Q66*hdiff3);

        him1 = hi;

    }

    assert(this->thickness > 0);

    this->ABDmat->set_data(1, 0, this->ABDmat->get_data(0, 1));
    this->ABDmat->set_data(2, 0, this->ABDmat->get_data(0, 2));
    this->ABDmat->set_data(2, 1, this->ABDmat->get_data(1, 2));

    this->ABDmat->divide_data(3, 0, 2.);
    this->ABDmat->divide_data(3, 1, 2.);
    this->ABDmat->divide_data(3, 2, 2.);
    this->ABDmat->divide_data(4, 1, 2.);
    this->ABDmat->divide_data(4, 2, 2.);
    this->ABDmat->divide_data(5, 2, 2.);

    this->ABDmat->set_data(1, 3, this->ABDmat->get_data(3, 1));
    this->ABDmat->set_data(2, 3, this->ABDmat->get_data(3, 2));
    this->ABDmat->set_data(2, 4, this->ABDmat->get_data(4, 2));

    this->ABDmat->set_data(4, 0, this->ABDmat->get_data(3, 1));
    this->ABDmat->set_data(5, 0, this->ABDmat->get_data(3, 2));
    this->ABDmat->set_data(5, 1, this->ABDmat->get_data(4, 2));

    this->ABDmat->set_data(0, 3, this->ABDmat->get_data(3, 0));
    this->ABDmat->set_data(1, 3, this->ABDmat->get_data(4, 0));
    this->ABDmat->set_data(2, 3, this->ABDmat->get_data(5, 0));
    this->ABDmat->set_data(0, 4, this->ABDmat->get_data(3, 1));
    this->ABDmat->set_data(1, 4, this->ABDmat->get_data(4, 1));
    this->ABDmat->set_data(2, 4, this->ABDmat->get_data(5, 1));
    this->ABDmat->set_data(0, 5, this->ABDmat->get_data(3, 2));
    this->ABDmat->set_data(1, 5, this->ABDmat->get_data(4, 2));
    this->ABDmat->set_data(2, 5, this->ABDmat->get_data(5, 2));

    this->ABDmat->divide_data(3, 3, 3.);
    this->ABDmat->divide_data(3, 4, 3.);
    this->ABDmat->divide_data(3, 5, 3.);
    this->ABDmat->divide_data(4, 4, 3.);
    this->ABDmat->divide_data(4, 5, 3.);
    this->ABDmat->divide_data(5, 5, 3.);

    this->ABDmat->set_data(4, 3, this->ABDmat->get_data(3, 4));
    this->ABDmat->set_data(5, 3, this->ABDmat->get_data(3, 5));
    this->ABDmat->set_data(5, 4, this->ABDmat->get_data(4, 5));

    int successful = inverse_matrix2(this->ABDmat, this->ABDinv);

    if(!successful)
    {
        cout << "Unable to invert laminate ABD matrix!\n";
        return;
    }

    double tmp = 1./this->thickness;

    this->Exx = tmp/this->ABDinv->get_data(0, 0);
    this->Eyy = tmp/this->ABDinv->get_data(1, 1);
    this->Gxy = tmp/this->ABDinv->get_data(2, 2);
    this->nuxy = -this->ABDinv->get_data(0, 1)/this->ABDinv->get_data(0, 0);
    this->nuyx = -this->ABDinv->get_data(0, 1)/this->ABDinv->get_data(1, 1);

    this->calculate_unit_stress();

}

void OrthotropicLaminate::calculate_unit_stress(void)
{

    double *unit_loads = NULL;
    unit_loads = (double *)calloc((size_t)6, sizeof(double));

    this->local_ply_strain->init(this->stackup.size(), 6, 3);
    this->local_ply_stress->init(this->stackup.size(), 6, 3);

    double global_ply_strain[3];
    double to_radians = 0.01745329251994329576923690768489;

    double *global_unit_strains = NULL;

    global_unit_strains = (double *)calloc((size_t)6, sizeof(double));

    for(unsigned int i = 0; i < 6; i ++)
    {

        memset(&unit_loads[0], 0, sizeof(double)*6);
        unit_loads[i] = 1.;

        multiply_matrix_and_vector2(this->ABDinv,
                                   (const double *)unit_loads,
                                   global_unit_strains);

        double z = -this->thickness/2.;

        for(unsigned int j = 0; j < this->stackup.size(); j++)
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

            OrthotropicMaterial *material = &this->stackup[j].material;

            // local ply stress
            double f11 = e11*material->C11 + e22*material->C12;
            double f22 = e11*material->C12 + e22*material->C22;
            double f12 = e12*material->C66;

            this->local_ply_strain->set_data(j, i, 0, e11);
            this->local_ply_strain->set_data(j, i, 1, e22);
            this->local_ply_strain->set_data(j, i, 2, e12);

            this->local_ply_stress->set_data(j, i, 0, f11);
            this->local_ply_stress->set_data(j, i, 1, f22);
            this->local_ply_stress->set_data(j, i, 2, f12);

            z += this->stackup[j].thickness/2.;
        }
    }

    free(unit_loads);
    unit_loads = NULL;

    free(global_unit_strains);
    global_unit_strains = NULL;

}

void OrthotropicLaminate::set_number_of_plies(unsigned int size)
{
    this->stackup.resize(size);
}

OrthotropicLamina *OrthotropicLaminate::get_ply(unsigned int i)
{
    return &this->stackup[i];
}

double OrthotropicLaminate::get_unit_strain(unsigned int ply, unsigned int load, unsigned int component)
{
    return this->local_ply_strain->get_data(ply, load, component);
}

double OrthotropicLaminate::get_unit_stress(unsigned int ply, unsigned int load, unsigned int component)
{
    return this->local_ply_stress->get_data(ply, load, component);
}

PlyStressStrain *OrthotropicLaminate::apply_loads(Array2D<double> *loads)
{
    OrthotropicMaterial *material;

    //assert (this->local_ply_strain != NULL);
    //assert (this->local_ply_stress != NULL);
    assert (this->stackup.size() > 0);

    unsigned int num_loads = loads->rows;

    // i = load #, j = ply #, k = component
    // 0-2 = stress, 3 - 5 = strain, 6 - 10 = stress allowable, 11 - 15 = strain allowable
    PlyStressStrain *results = new PlyStressStrain();
    results->stress->init(num_loads, this->stackup.size());
    results->strain->init(num_loads, this->stackup.size());

    unsigned int i, j, k;

    StressStrain2D *stress_ = results->stress;
    StressStrain2D *strain_ = results->strain;

    for(i = 0; i < num_loads; i++)
    {
        for(j = 0; j < this->stackup.size(); j++)
        {

            StressStrain *stress = stress_->get_data_ptr(i, j);
            StressStrain *strain = strain_->get_data_ptr(i, j);

            for(k = 0; k < 6; k++)
            {

                double load = loads->get_data(i, k);

                stress->a11 += load*this->local_ply_stress->get_data(j, k, 0);
                stress->a22 += load*this->local_ply_stress->get_data(j, k, 1);
                stress->a12 += load*this->local_ply_stress->get_data(j, k, 2);

                strain->a11 += load*this->local_ply_strain->get_data(j, k, 0);
                strain->a22 += load*this->local_ply_strain->get_data(j, k, 1);
                strain->a12 += load*this->local_ply_strain->get_data(j, k, 2);
            }

            material = &this->stackup[j].material;

            stress->A1t = abs(material->F1t);
            stress->A1c = abs(material->F1c);
            stress->A2t = abs(material->F2t);
            stress->A2c = abs(material->F2c);
            stress->A12 = abs(material->F12);

            strain->A1t = abs(material->E1t);
            strain->A1c = abs(material->E1c);
            strain->A2t = abs(material->E2t);
            strain->A2c = abs(material->E2c);
            strain->A12 = abs(material->E12);

        }
    }

    return results;

}