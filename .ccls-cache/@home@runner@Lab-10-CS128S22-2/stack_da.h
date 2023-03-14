#ifndef STACK_DA_H_
#define STACK_DA_H_

#include "data_structures/dynamic_array.h"


class StackDA {
  public:
    StackDA();
    ~StackDA();

    void Push(int value);
    int Pop();
    int Peek();
    int GetSize();
    bool IsEmpty();

  private:
    DynamicArray* contents_;
};

#endif