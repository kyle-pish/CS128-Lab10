#include "queue_ll.h"

QueueLL::QueueLL() {
  this->contents_ = new LinkedList;
}

QueueLL::~QueueLL() {
  delete this->contents_;
  this->contents_ = 0;
}

//Takes as input an int; adds it to the end of the queue
void QueueLL::Enqueue(int value) {
  this->contents_->Append(value);
}

//Returns and removes the int at the front of the queue
int QueueLL::Dequeue() {
  return this->contents_->PopAt(0);
}

//Returns, but does not remove, the int at the front of the queue
int QueueLL::Peek() {
  return this->contents_->Get(0);
}

//Returns the size of the queue as an int
int QueueLL::GetSize() {
  return this->contents_->GetSize();
}

//Returns true if the queue is empty, and false otherwise
bool QueueLL::IsEmpty() {
  if (this->contents_->GetSize() == 0) {
    return true;
  }
  else {
    return false;
  }
}
