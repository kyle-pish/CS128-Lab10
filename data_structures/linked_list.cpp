#include <iostream>

#include "linked_list.h"

// Create a new linked list.
LinkedList::LinkedList() {
  // Initialize the head pointer to null, to indicate 0 nodes.
  this->head_ = 0;
  
  this->size_ = 0;
}

LinkedList::~LinkedList() {
  // If there is a head node, delete it.
  // Recursive destructor in LLNode should take care
  // of remaining nodes in the LL.
  if (this->head_ != 0) {
    delete this->head_;
  }
}

// Add a new node with the given value to the end of the LL.
void LinkedList::Append(int new_data) {
  // Special case: if the LL has no nodes in it yet,
  // we need to deal with that case separately
  // and manipulate the head pointer ourselves.
  if (this->head_ == 0) {
    this->head_ = new LLNode(new_data);
  }
  else {
    // Otherwise, LL is not empty, so traversal is required.
    // Start a pointer at the head.
    LLNode* current_node = this->head_;

    // Traversing the linked list until the current_node
    // pointer points at the last node.
    while (current_node->next_ != 0) {
      current_node = current_node->next_;
    }

    // So at this point here, current_node should be
    // a pointer to the last node because the last node's
    // next_ points at 0.
    current_node->next_ = new LLNode(new_data);
  }

  // Update the stored size attribute
  this->size_++;
}

// Return the data in the node located at the specified index.
int LinkedList::Get(int index) {
  // Start the pointer at the head
  LLNode* current_node = this->head_;

  // Index counter
  int counter = 0;

  // Traverse the LL until we reach the end or until
  // the given index is reached.
  // HOPEFULLY the user didn't give us a too-large index.
  // If they did, this will seg-fault.
  while (current_node != 0 && counter < index) {
    counter++;
    current_node = current_node->next_;
  }

  // Pointer should now be pointing at correct index
  // (or null, if a bad index was given).
  return current_node->data_;
}


void LinkedList::Print() {
  LLNode* current = this->head_;
  std::cout << "[ ";
  while (current != 0) {
    std::cout << current->data_ << " ";
    current = current->next_;
  }
  std::cout << "]" << std::endl;
}

int LinkedList::GetSize() {
  return this->size_;
  // Re: "two ways to do it"
  // This *could* also just traverse the list here to count
  // the number of nodes, but storing and updating it on list
  // modifications is more efficient.
}

bool LinkedList::Contains(int contains_me) {
  LLNode* current = this->head_;
  while (current != 0) {
    if (current->data_ == contains_me) {
      return true;
    }
    current = current->next_;
  }
  return false;
}

int LinkedList::Count(int count_me) {
  LLNode* current = this->head_;
  int count = 0;
  while (current != 0) {
    if (current->data_ == count_me) {
      count++;
    }
    current = current->next_;
  }
  return count;
}

void LinkedList::Set(int index, int value) {
  LLNode* current = this->head_;
  int cur_index = 0;
  while (current != 0 && cur_index < index) {
    current = current->next_;
    cur_index++;
  }
  current->data_ = value;
}

int LinkedList::Pop() {
  // demonstrating the two-pointer way of doing it
  LLNode* current = this->head_;

  // Special case: one node
  if (current->next_ == 0) {
    int ret = this->head_->data_;
    delete this->head_;
    this->head_ = 0;
    this->size_--;
    return ret;
  }

  // Otherwise, traverse until current is the final node.
  // Prev always points to the node before current.
  LLNode* prev = 0;
  while (current->next_ != 0) {
    prev = current;
    current = current->next_;
  }
  int ret = current->data_;
  delete current;
  prev->next_ = 0;
  this->size_--;
  return ret;
}

void LinkedList::Insert(int index, int value) {
  LLNode* new_node = new LLNode(value);

  // Special case: inserting at head
  if (index == 0) {
    new_node->next_ = this->head_;
    this->head_ = new_node;
  }
  else {
    LLNode* current = this->head_;
    LLNode* prev = 0;
    int cur_index = 0;
    while (current != 0 && cur_index < index) {
      prev = current;
      current = current->next_;
      cur_index++;
    }
  
    new_node->next_ = current;
    prev->next_ = new_node;
  }

  this->size_++;
}

int LinkedList::PopAt(int index) {
  LLNode* current = this->head_;

  // Special case: Popping first node
  if (index == 0) {
    int ret = this->head_->data_;
    this->head_= current->next_;
    current->next_ = 0;  // IMPORTANT: disconnect this node from
                         // remaining nodes so delete doesn't
                         // recursively delete them, too.
    delete current;
    this->size_--;
    return ret;
  }

  // Otherwise, traverse until we find current the correct node.
  // Prev always points to the node before current.
  LLNode* prev = 0;
  int cur_index = 0;
  while (current != 0 && cur_index < index) {
    prev = current;
    current = current->next_;
    cur_index++;
  }
  int ret = current->data_;
  prev->next_ = current->next_;
  current->next_ = 0;  // IMPORTANT: disconnect this node from
                       // remaining nodes so delete doesn't
                       // recursively delete them, too.
  delete current;
  this->size_--;
  return ret;
}
