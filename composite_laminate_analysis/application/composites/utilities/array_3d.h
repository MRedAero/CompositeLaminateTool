#ifndef ARRAY_3D_H
#define ARRAY_3D_H

#include <stdlib.h>

using namespace std;

template <class T>
class Array3D
{
    inline unsigned int index(unsigned int, unsigned int, unsigned int);

    unsigned int size_i23;

    public:
    unsigned int size_i1, size_i2, size_i3;
    T *data=NULL;

    Array3D(unsigned int, unsigned int, unsigned int);
    void init(unsigned int, unsigned int, unsigned int);
    ~Array3D(void);

    T get_data(unsigned int, unsigned int, unsigned int);
    void set_data(unsigned int, unsigned int, unsigned int, T);
    void increment_data(unsigned int, unsigned int, unsigned int, T);
    void divide_data(unsigned int, unsigned int, unsigned int, T);
};

#endif //ARRAY_3D_H