#include "stack_ll.h"

StackLL::StackLL() {
  this->contents_ = new LinkedList();
}

StackLL::~StackLL() {
  delete this->contents_;
  this->contents_ = 0;
}

//Takes an int as input and adds it to the top of the stack (in this case, the end of the Linked List)
void StackLL::Push(int value) {
  this->contents_->Append(value);
}

//Returns and removes the int at the top of the stack
int StackLL::Pop() {
  return this->contents_->Pop();
}

//Returns, but does not remove, the int at the top of the stack
int StackLL::Peek() {
  return this->contents_->Get(0);
}

//Returns the size of the stack as an int
int StackLL::GetSize() {
  return this->contents_->GetSize();
}

//Returns true if the stack is empty, and false otherwise.
bool StackLL::IsEmpty() {
  if (this->contents_->GetSize() == 0) {
    return true;
  }

  else {
    return false;
  }
}
