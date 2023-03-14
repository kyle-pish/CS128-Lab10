#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <string>

#include "partially_filled_array.h"

class DynamicArray : public PartiallyFilledArray {
  public:
    DynamicArray(int initial_capacity);
    DynamicArray(int integers[], int size);
    ~DynamicArray();

    // Critical method for DynamicArray
    void Grow();

    // Methods that must be overridden
    void Append(int new_int);
    void Insert(int insert_me, int index);

    // New methods
    void Extend(DynamicArray& other);
    DynamicArray Slice(int start, int stop);
    void Clear();
};

void DynamicArray_main();

#endif