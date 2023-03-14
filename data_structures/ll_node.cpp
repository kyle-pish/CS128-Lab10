#include <iostream>

#include "ll_node.h"

// Create a new linked list node with the given data and no next node.
LLNode::LLNode(int data) {
  this->data_ = data;
  this->next_ = 0;
}

// (Recursively) destroy this LLNode and all following it.
LLNode::~LLNode() {
  if (this->next_ != 0) {
    delete this->next_;
  }
}
