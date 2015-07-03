#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stdlib.h>
#include "array_2d.h"

template <class T>
inline unsigned int Array2D<T>::index(unsigned int i1, unsigned int i2)
{
    return this->cols*i1 + i2;
}

template <class T>
Array2D<T>::Array2D(unsigned int rows, unsigned int cols)
{
    this->init(rows, cols);
}

template <class T>
void Array2D<T>::init(unsigned int rows, unsigned int cols)
{
    this->rows = rows;
    this->cols = cols;

    if(this->data) free(this->data);

    this->data = (T *)calloc((size_t)rows*cols, sizeof(T));

    //assert (this->data != NULL);
}

template <class T>
Array2D<T>::~Array2D(void)
{
    if(this->data) free(this->data);

    this->data = NULL;
}

template <class T>
T Array2D<T>::get_data(unsigned int i1, unsigned int i2)
{
    return this->data[this->index(i1, i2)];
}

template <class T>
T *Array2D<T>::get_data_ptr(unsigned int i1, unsigned int i2)
{
    return &this->data[this->index(i1, i2)];
}

template <class T>
void Array2D<T>::set_data(unsigned int i1, unsigned int i2, T value)
{
    this->data[this->index(i1, i2)] = value;
}

template <class T>
void Array2D<T>::increment_data(unsigned int i1, unsigned int i2, T value)
{
    this->data[this->index(i1, i2)] += value;
}

template <class T>
void Array2D<T>::divide_data(unsigned int i1, unsigned int i2, T value)
{
    this->data[this->index(i1, i2)] /= value;
}

template <class T>
void Array2D<T>::print_array(void)
{
    unsigned int i, j;

    for(i = 0; i < this->rows; i++)
    {
        for(j = 0; j < this->cols; j++) cout << setw(20) << this->get_data(i, j);
        cout << "\n";
    }
}

template class Array2D<unsigned int>;
template class Array2D<int>;
template class Array2D<long>;
template class Array2D<float>;
template class Array2D<double>;
