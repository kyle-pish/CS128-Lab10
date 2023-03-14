#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "ll_node.h"

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    void Append(int new_data);
    int Get(int index);

    void Print();
    int GetSize();
    bool Contains(int contains_me);
    int Count(int count_me);
    void Set(int index, int value);
    int Pop();
    void Insert(int index, int value);
    int PopAt(int index);

  private:
    LLNode* head_;
    int size_;  // store the current number of nodes in the list
};

#endif
