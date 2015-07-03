#ifndef BASIC_ARRAY_2D_H
#define BASIC_ARRAY_2D_H

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stdlib.h>

using namespace std;

template <class T>
class BasicArray2D
{
    inline unsigned int index(unsigned int, unsigned int);

    public:
    unsigned int rows, cols;
    T *data=NULL;

    BasicArray2D(unsigned int, unsigned int);
    void init(unsigned int, unsigned int);
    ~BasicArray2D(void);

    T get_data(unsigned int, unsigned int);
    T *get_data_ptr(unsigned int, unsigned int);
};

template <class T>
inline unsigned int BasicArray2D<T>::index(unsigned int i1, unsigned int i2)
{
    return this->cols*i1 + i2;
}

template <class T>
BasicArray2D<T>::BasicArray2D(unsigned int rows, unsigned int cols)
{
    this->init(rows, cols);
}

template <class T>
void BasicArray2D<T>::init(unsigned int rows, unsigned int cols)
{
    this->rows = rows;
    this->cols = cols;

    if(this->data) free(this->data);

    this->data = (T *)calloc((size_t)rows*cols, sizeof(T));

}

template <class T>
BasicArray2D<T>::~BasicArray2D(void)
{
    if(this->data) free(this->data);

    this->data = NULL;
}

template <class T>
T BasicArray2D<T>::get_data(unsigned int i1, unsigned int i2)
{
    return this->data[this->index(i1, i2)];
}

template <class T>
T *BasicArray2D<T>::get_data_ptr(unsigned int i1, unsigned int i2)
{
    return &this->data[this->index(i1, i2)];
}

#endif //BASIC_ARRAY_2D_H