#include "stack_da.h"

StackDA::StackDA() {
  this->contents_ = new DynamicArray(1);
}

StackDA::~StackDA() {
  delete this->contents_;
  this->contents_ = 0;
}

//Takes an int as input and adds it to the top of the stack (in this case, the end of the Dynamic Array)
void StackDA::Push(int value) {
  this->contents_->Append(value);
}

//Returns and removes the int at the top of the stack
int StackDA::Pop() {
  return this->contents_->PopAt(this->contents_->GetSize() - 1);
}

//Returns, but does not remove, the int at the top of the stack
int StackDA::Peek() {
  return this->contents_->Get(this->contents_->GetSize() - 1);
}

//Returns the size of the stack as an int
int StackDA::GetSize() {
  return this->contents_->GetSize();
}

//Returns true if the stack is empty, and false otherwise.
bool StackDA::IsEmpty() {
  if (this->contents_->GetSize() == 0) {
    return true;
  }
  else {
    return false;
  }
}