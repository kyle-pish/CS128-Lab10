#include "queue_da.h"


QueueDA::QueueDA() {
  this->contents_ = new DynamicArray(1);
}

QueueDA::~QueueDA() {
  delete this->contents_;
  this->contents_ = 0;
}

void QueueDA::Enqueue(int value) {
  this->contents_->Append(value);
}

int QueueDA::Dequeue() {
  return this->contents_->PopAt(0);
}

int QueueDA::Peek() {
  return this->contents_->Get(0);
}

int QueueDA::GetSize() {
  return this->contents_->GetSize();
}

bool QueueDA::IsEmpty() {
  if (this->contents_->GetSize() == 0) {
    return true;
  }

  else {
    return false;
  }
}

