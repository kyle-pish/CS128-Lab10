#include "queue_da.h"


QueueDA::QueueDA() {
  this->contents_ = new DynamicArray(1);
}

QueueDA::~QueueDA() {
  delete this->contents_;
  this->contents_ = 0;
}

//Takes as input an int; adds it to the end of the queue
void QueueDA::Enqueue(int value) {
  this->contents_->Append(value);
}

//Returns and removes the int at the front of the queue
int QueueDA::Dequeue() {
  return this->contents_->PopAt(0);
}

//Returns, but does not remove, the int at the front of the queue
int QueueDA::Peek() {
  return this->contents_->Get(0);
}

//Returns the size of the queue as an int
int QueueDA::GetSize() {
  return this->contents_->GetSize();
}

//Returns true if the queue is empty, and false otherwise
bool QueueDA::IsEmpty() {
  if (this->contents_->GetSize() == 0) {
    return true;
  }

  else {
    return false;
  }
}

