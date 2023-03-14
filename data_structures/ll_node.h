#ifndef LL_NODE_H_
#define LL_NODE_H_


class LLNode {
  public:
    LLNode(int data);
    ~LLNode();

    int data_;
    LLNode* next_;  // A pointer to the next node in the LL
};


#endif
