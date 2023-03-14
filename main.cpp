//Kyle Pish and Josh Reed
//3/24/2022

#include <iostream>
#include "stack_ll.h"
#include "stack_da.h"
#include "queue_ll.h"
#include "queue_da.h"
#include "Timer.h"


void Test_StackLL() {
  StackLL stack_1;
  
  std::cout << stack_1.IsEmpty();
  std::cout << stack_1.GetSize();
  stack_1.Push(1);
  std::cout << stack_1.GetSize();
  stack_1.Push(2);
  std::cout << stack_1.GetSize();
  stack_1.Push(3);
  std::cout << stack_1.GetSize();
  std::cout << stack_1.IsEmpty();
  std::cout << stack_1.Pop();
  std::cout << stack_1.Pop();
  std::cout << stack_1.Peek();
  std::cout << stack_1.Pop();
  std::cout << stack_1.IsEmpty();

  //Should output 10123032111
  
}

void Test_StackDA() {
  StackLL stack_2;
  
  std::cout << stack_2.IsEmpty();
  std::cout << stack_2.GetSize();
  stack_2.Push(1);
  std::cout << stack_2.GetSize();
  stack_2.Push(2);
  std::cout << stack_2.GetSize();
  stack_2.Push(3);
  std::cout << stack_2.GetSize();
  std::cout << stack_2.IsEmpty();
  std::cout << stack_2.Pop();
  std::cout << stack_2.Pop();
  std::cout << stack_2.Peek();
  std::cout << stack_2.Pop();
  std::cout << stack_2.IsEmpty();

  //Should output 10123032111

}

void Test_QueueLL(){
  QueueLL queue;

  std::cout << queue.IsEmpty();
  std::cout << queue.GetSize();
  queue.Enqueue(1);
  queue.Enqueue(2);
  queue.Enqueue(3);
  std::cout << queue.IsEmpty();
  std::cout << queue.GetSize();
  std::cout << queue.Dequeue();
  std::cout << queue.Dequeue();
  std::cout << queue.Peek();
  std::cout << queue.Dequeue();

  //This should output 10031233
}

void Test_QueueDA() {
  QueueDA queue;

  std::cout << queue.IsEmpty();
  std::cout << queue.GetSize();
  queue.Enqueue(1);
  queue.Enqueue(2);
  queue.Enqueue(3);
  std::cout << queue.IsEmpty();
  std::cout << queue.GetSize();
  std::cout << queue.Dequeue();
  std::cout << queue.Dequeue();
  std::cout << queue.Peek();
  std::cout << queue.Dequeue();

  //This should output 10031233
}


void Time_StackDA() {

  for (int size = 10000; size <= 1000000; size += 10000) {

    StackDA stack;
    
    Timer t = Timer();
    t.go();

    for (int i = 0; i < size; i++) {
      stack.Push(i);
    }
  
    double time_in_sec = t.end();
    std::cout << time_in_sec << "," << size << std::endl;
  }
}

void Time_StackLL() {

  for (int size = 1000; size <= 50000; size += 1000) {

    StackLL stack;
    
    Timer t = Timer();
    t.go();

    for (int i = 0; i < size; i++) {
      stack.Push(i);
    }
  
    double time_in_sec = t.end();
    std::cout << time_in_sec << "," << size << std::endl;
  }
}

void Time_QueueDA() {

  for (int size = 1000; size <= 50000; size += 1000) {

    QueueDA queue;

    for (int i = 0; i < size; i++) {
      queue.Enqueue(i);
    }
    
    Timer t = Timer();
    t.go();

    for (int i = 0; i < size; i++) {
      queue.Dequeue();
    }
  
    double time_in_sec = t.end();
    std::cout << time_in_sec << "," << size << std::endl;
  }
}

void Time_QueueLL() {

  for (int size = 1000; size <= 50000; size += 1000) {

    QueueLL queue;

    for (int i = 0; i < size; i++) {
      queue.Enqueue(i);
    }
    
    Timer t = Timer();
    t.go();

    for (int i = 0; i < size; i++) {
      queue.Dequeue();
    }
  
    double time_in_sec = t.end();
    std::cout << time_in_sec << "," << size << std::endl;
  }
}

int main() {
  Test_StackLL();
  Test_StackDA();
  Test_QueueLL();
  Test_QueueDA();
  //Time_StackDA();
    //The plot has a relatively linear increase. The sudden jumps seem random in the actual data due to the noise, but one can expect jumps in time for every power of 2, as the list will have to reallocate again at those intervals.
  //Time_StackLL();
    //This plot has an increase to resembles exponential, as opposed to a nearly linear incrase for the DA implementation. 
    //This is because, by having to traverse the list, each individual push takes longer than the last. So in addition to each data point having more data to push,
    //the further back in the list the data is being added, the longer it takes to add it.

  //Time_QueueDA();
  Time_QueueLL();


  //Below is the testing of the Timer object done in steps 1-6 of Part 2. Not strictly necessary for the data, but kept (and commented out) for clarity that we did that portion.

  /*
  // Create a Timer object to time our benchmark.
  // You’ll only need one Timer object, and you can reuse it.
  Timer t = Timer();
  // Call t.go() before the code we want to time.
  t.go();
  //
  // The code to be timed goes here...
  for (int i = 0; i < 10000; i++) { 
    std::cout << "Sup";
  }
  // Call t.end() immediately after the code you are timing.
  // The return value of t.end() is the running time in seconds.
  double time_in_sec = t.end();
  std::cout << time_in_sec;
  */
}

