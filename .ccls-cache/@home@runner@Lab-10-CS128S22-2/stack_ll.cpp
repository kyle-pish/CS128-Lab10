#include "stack_ll.h"

StackLL::StackLL() {
  this->contents_ = new LinkedList();
}

StackLL::~StackLL() {
  delete this->contents_;
  this->contents_ = 0;
}

void StackLL::Push(int value) {
  this->contents_->Append(value);
}

int StackLL::Pop() {
  return this->contents_->Pop();
}

int StackLL::Peek() {
  return this->contents_->Get(0);
}

int StackLL::GetSize() {
  return this->contents_->GetSize();
}

bool StackLL::IsEmpty() {
  if (this->contents_->GetSize() == 0) {
    return true;
  }

  else {
    return false;
  }
}
