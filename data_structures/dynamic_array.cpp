#include <iostream>

#include "dynamic_array.h"

DynamicArray::DynamicArray(int initial_capacity) : PartiallyFilledArray(initial_capacity) {}

DynamicArray::DynamicArray(int integers[], int size) : PartiallyFilledArray(integers, size) {}

DynamicArray::~DynamicArray() {}

void DynamicArray::Grow() {
  // increase (double) the capacity
  this->capacity_ *= 2;

  // allocate a new array with the larger capacity
  int* new_array = new int[this->capacity_];

  // copy values from the old array to the new one
  for (int i = 0 ; i < this->size_ ; i++) {
    new_array[i] = this->contents_[i];
  }

  // deallocate the old array
  delete this->contents_;

  // re-point our pointer to the new array
  this->contents_ = new_array;
}


// Just this one method is provided for you as an example
// of how DynamicArray can override a method from
// PartiallyFilledArray and still call the method
// that it overrode.
void DynamicArray::Append(int new_int) {
  if (this->IsFull()) {
    // If we're full, we need to grow the capacity
    this->Grow();
  }

  // At this point, we know there is enough capacity,
  // so we'll use the *parent* class's version of Append()
  // to complete the work instead of just rewriting basically
  // the same code here.  Code reuse is good!
  PartiallyFilledArray::Append(new_int);
}


void DynamicArray::Insert(int insert_me, int index) {
  if (this->IsFull()) {
    // If we're full, we need to grow the capacity
    this->Grow();
  }
  // Call the parent class version of the method.
  PartiallyFilledArray::Insert(insert_me, index);
}

void DynamicArray::Extend(DynamicArray& other) {
  for (int i = 0 ; i < other.size_ ; i++) {
    this->Append(other.Get(i));
  }

  // Or you could be a bit more efficient and:
  // 1) resize the array to the final needed capacity
  // 2) copy values over directly from other.contents_ in a loop.
  // But it's not a huge difference...
}

DynamicArray DynamicArray::Slice(int start, int stop) {
  DynamicArray result = DynamicArray(stop-start);
  for (int i = start ; i < stop ; i++) {
    result.Append(this->Get(i));
  }

  return result;
}

void DynamicArray::Clear() {
  this->size_ = 0;
}


void DynamicArray_main() {
  DynamicArray A = DynamicArray(1);

  // Testing Append
  for (int i = 10 ; i < 100 ; i += 10) {
    A.Append(i); 
  }
  A.Print();
  std::cout << "A Capacity: " << A.GetCapacity() << std::endl;

  // Testing Insert
  for (int i = 0 ; i < 8 ; i++) {
    A.Insert(-500, 4);
    A.Print();
  }

  // Just to check that inherited methods like Remove still works
  for (int i = 0 ; i < 8 ; i++) {
    A.Remove(-500);
    A.Print();
  }
  std::cout << "A Capacity: " << A.GetCapacity() << std::endl;

  // Testing the constructor that takes an array of ints
  int testvals[] = {5, 4, 3, 2, 1};
  DynamicArray B = DynamicArray(testvals, 5);
  B.Print();
  std::cout << "B Capacity: " << B.GetCapacity() << std::endl;
  // Should show us [ 5 4 3 2 1 ] and a capacity of 10

  // Testing Extend
  DynamicArray C = DynamicArray(1);
  C.Print();
  C.Extend(B);
  C.Print();
  C.Extend(B);
  C.Print();
  C.Extend(B);
  C.Print();

  // Testing Slice
  DynamicArray D = C.Slice(3, 6);
  D.Print();  // should be [ 2 1 5 ]
  std::cout << "D Capacity: " << D.GetCapacity() << std::endl;

  D.Clear();
  D.Print();  // [ ]
  std::cout << "D Capacity: " << D.GetCapacity() << std::endl;

}