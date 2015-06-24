#include <iostream>
#include "LaminateOrthotropic.h"

using namespace std;

int main() {
    MaterialOrthotropic material;
    LaminateOrthotropic laminate;

    material.E11 = 27000000.;
    material.E22 = 1500000.;
    material.nu12 = 0.35;
    material.G12 = 1100000.;

    laminate.stackup.resize(4);

    laminate.stackup[0].material = material;
    laminate.stackup[0].thickness = 0.008;
    laminate.stackup[0].orientation = 0.;

    laminate.stackup[1].material = material;
    laminate.stackup[1].thickness = 0.008;
    laminate.stackup[1].orientation = 45.;

    laminate.stackup[2].material = material;
    laminate.stackup[2].thickness = 0.008;
    laminate.stackup[2].orientation = -45.;

    laminate.stackup[3].material = material;
    laminate.stackup[3].thickness = 0.008;
    laminate.stackup[3].orientation = 90.;

    //laminate.stackup[4].material = material;
    //laminate.stackup[4].thickness = 0.008;
    //laminate.stackup[4].orientation = 90.;

    //laminate.stackup[5].material = material;
    //laminate.stackup[5].thickness = 0.008;
    //laminate.stackup[5].orientation = -45.;

    //laminate.stackup[6].material = material;
    //laminate.stackup[6].thickness = 0.008;
    //laminate.stackup[6].orientation = 45.;

    //laminate.stackup[7].material = material;
    //laminate.stackup[7].thickness = 0.008;
    //laminate.stackup[7].orientation = 0.;

    laminate.calculate_laminate_properties();

    int k = 4;

    for(int i = 0; i < 4; i++)
    {

        cout << laminate.local_ply_strain[k][i].data[0]*1000000. << ",";
        cout << laminate.local_ply_strain[k][i].data[1]*1000000. << ",";
        cout << laminate.local_ply_strain[k][i].data[2]*1000000.;
        cout << "\n";

    }

    for(int i = 0; i < 4; i++)
    {

        cout << laminate.local_ply_stress[k][i].data[0] << ",";
        cout << laminate.local_ply_stress[k][i].data[1] << ",";
        cout << laminate.local_ply_stress[k][i].data[2];
        cout << "\n";

    }


}