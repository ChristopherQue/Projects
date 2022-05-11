// bst.h

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <sstream>
#include <queue>

namespace cop4530 {

static const int default_threshold_value = 1;

using namespace std;

template <typename T>
class BST {
  public:
    BST(int th = default_threshold_value);
    BST(const string input, int th = default_threshold_value);  // constructor
    BST(const BST& v);  // copy constructor
    BST(BST&& v);  // move constructor
    ~BST();  // destructor
    void buildFromInputString(const string input);
    const BST & operator=(const BST & n);
    const BST & operator=(BST && n);
    bool empty();
    void printInOrder() const;
    void printLevelOrder() const;
    int numOfNodes() const;
    int height() const;
    void makeEmpty();
    void insert(const T& v);
    void insert(T &&v);
    void remove(const T& v);
    bool contains(const T& v);

  private:
    struct BSTNode {
      T element;
      int counter;
      BSTNode* left;
      BSTNode* right;
      BSTNode(const T& theElement, BSTNode* lp, BSTNode* rp, int ct = 0)
        :element(theElement), left(lp), right(rp), counter(ct) {
      }
      BSTNode(const T&&theelement, BSTNode* lp, BSTNode*rp,int ct=0)
        :element(std::move(theelement)),left(lp),right(rp),counter(ct) {
      }
    };

    BSTNode* root;
    int threshold;
    typename BST<T>::BSTNode* clone(BSTNode* t)const;
    void printInOrder(BSTNode *t)const;
    void printLevelOrder(BSTNode *t) const;  // does not need to be recursive
    void makeEmpty(BSTNode* &t);
    void insert(const T& v, BSTNode *&t);
    void insert(T&& v, BSTNode *&t);
    void remove(const T& v, BSTNode *&t);
    bool contains(const T& v, BSTNode *&t, BSTNode *& p);
    int numOfNodes(BSTNode *t) const;
    int height(BSTNode *t)const;
    BSTNode* clone(BSTNode *t);
    BSTNode * min(BSTNode * t) const;
};



#include "bst.hpp"
}
#endif
