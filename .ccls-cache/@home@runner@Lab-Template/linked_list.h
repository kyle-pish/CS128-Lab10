// Original Author: Brian Law
//
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "ll_node.h"

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    void Append(std::string new_data);
    std::string Get(int index);

  private:
    LLNode* head_;
};

#endif