#ifndef ARRAY_3D_H
#define ARRAY_3D_H

#include <iostream>
#include <iomanip>
#include <assert.h>
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

template <class T>
inline unsigned int Array3D<T>::index(unsigned int i1, unsigned int i2, unsigned int i3)
{
    return this->size_i23*i1 + this->size_i3*i2 + i3;
}

template <class T>
Array3D<T>::Array3D(unsigned int size_i1, unsigned int size_i2, unsigned int size_i3)
{
    this->init(size_i1, size_i2, size_i3);
}

template <class T>
void Array3D<T>::init(unsigned int size_i1, unsigned int size_i2, unsigned int size_i3)
{
    this->size_i1 = size_i1;
    this->size_i2 = size_i2;
    this->size_i3 = size_i3;

    this->size_i23 = this->size_i2*this->size_i3;

    if(this->data) free(this->data);

    this->data = (T *)calloc((size_t)size_i1*size_i2*size_i3, sizeof(T));

    //assert (this->data != NULL);
}

template <class T>
Array3D<T>::~Array3D(void)
{
    if(this->data) free(this->data);

    this->data = NULL;
}

template <class T>
T Array3D<T>::get_data(unsigned int i1, unsigned int i2, unsigned int i3)
{
    return this->data[this->index(i1, i2, i3)];
}

template <class T>
void Array3D<T>::set_data(unsigned int i1, unsigned int i2, unsigned int i3, T value)
{
    this->data[this->index(i1, i2, i3)] = value;
}

template <class T>
void Array3D<T>::increment_data(unsigned int i1, unsigned int i2, unsigned int i3, T value)
{
    this->data[this->index(i1, i2, i3)] += value;
}

template <class T>
void Array3D<T>::divide_data(unsigned int i1, unsigned int i2, unsigned int i3, T value)
{
    this->data[this->index(i1, i2, i3)] /= value;
}

#endif //ARRAY_3D_H