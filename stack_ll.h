#ifndef STACK_LL_H_
#define STACK_LL_H_
#include "data_structures/linked_list.h"

class StackLL {
  public:
    StackLL();
    ~StackLL();

    void Push(int value);
    int Pop();
    int Peek();
    int GetSize();
    bool IsEmpty();

  private:
    LinkedList* contents_;
};

#endif