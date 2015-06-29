#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include <stdlib.h>

using namespace std;

template <class T>
class Array2D
{
    inline unsigned int index(unsigned int, unsigned int);

    public:
    unsigned int rows, cols;
    T *data=NULL;


    Array2D(unsigned int, unsigned int);
    void init(unsigned int, unsigned int);
    ~Array2D(void);

    T get_data(unsigned int, unsigned int);
    void set_data(unsigned int, unsigned int, T);
    void increment_data(unsigned int, unsigned int, T);
    void divide_data(unsigned int, unsigned int, T);
    void print_array(void);
};

#endif //ARRAY_2D_H