// Stack.h

#ifndef COP4530_STACK_H
#define COP4530_STACK_H

#include <iostream>
#include <vector>

namespace cop4530 {

template <typename T>
class Stack {
  public:
    Stack();  // default constructor
    ~Stack(); // destructor
    Stack(const Stack<T> &rhs); // copy constructor
    Stack(Stack &&rhs);  // move constructor
    Stack& operator=(const Stack &rhs);  // copy assignment operator
    Stack& operator=(Stack &&rhs);  // move assignment operator
    bool empty() const;  // return true if there is no element in stack, flase otherwise
    T& top(); // reference to first element in Stack
    const T& top() const; // const version of ^
    void pop();  // remove first element and discard it
    void push(const T& val);  // add new element val to the Stack
    void push (T&& val);  // add new element val to the stack, should be moved instead of copied
    int size() const;  // return number of elements in the current stack

  private:
    std::vector<T> stk;

  };

  template <typename T>
  bool operator==(const Stack<T> & lhs, const Stack<T> & rhs);

  template <typename T>
  bool operator!=(const Stack<T> & lhs, const Stack<T> & rhs);

  template <typename T>
  bool operator<=(const Stack<T> & a, const Stack<T> & b);

  template <typename T>
  std::ostream & operator<<(std::ostream &os, const Stack<T> &a);

  #include "Stack.hpp"

}
#endif
