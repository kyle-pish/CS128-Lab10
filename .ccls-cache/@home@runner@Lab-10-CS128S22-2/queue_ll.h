#ifndef QUEUE_LL_H_
#define QUEUE_LL_H_

#include "data_structures/linked_list.h"

class QueueLL {

  public:
    QueueLL();
    ~QueueLL();

    void Enqueue(int value);
    int Dequeue();
    int Peek();
    int GetSize();
    bool IsEmpty();

  private:
    LinkedList* contents_;

};

#endif