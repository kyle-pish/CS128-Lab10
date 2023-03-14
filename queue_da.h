#ifndef QUEUE_DA_H_
#define QUEUE_DA_H_

#include "data_structures/dynamic_array.h"

class QueueDA {
  public:
    QueueDA();
    ~QueueDA();

    void Enqueue(int value);
    int Dequeue();
    int Peek();
    int GetSize();
    bool IsEmpty();

  private:
    DynamicArray* contents_;
};

#endif