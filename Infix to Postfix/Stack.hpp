// Stack.hpp
using namespace std;

template<typename T>
Stack<T>::Stack() {  // default constructor

}

template<typename T>
Stack<T>::~Stack() {   // destructor
    stk.clear();
}

template<typename T>
Stack<T>::Stack(const Stack<T> &rhs) {   // copy constructor
  *this = rhs;
}

template<typename T>
Stack<T>::Stack(Stack<T> &&rhs) {   // move constructor
  stk = move(rhs.stk);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &rhs) {  // copy assignment operator
  if(*this != rhs)
    stk = rhs.stk;
  return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> &&rhs) {  // move assignment operator
  stk = move(rhs.data);
  return *this;
}

template<typename T>
bool Stack<T>::empty() const {  // return true if there is no element in stack, false otherwise
  return size() == 0;
}

template<typename T>
T& Stack<T>::top() { // reference to first element in Stack
  return stk.back();
}

template<typename T>
const T& Stack<T>::top() const { // const version of ^
  return stk.back();
}

template<typename T>
void Stack<T>::pop() {  // remove first element and discard it
  if(stk.size() != 0)
    stk.pop_back();
}

template<typename T>
void Stack<T>::push(const T& val) {  // add new element val to the Stack
  stk.push_back(val);
}

template<typename T>
void Stack<T>::push(T && val) {  // add new element val to the stack, should be moved instead of copied
  stk.push_back(move(val));
}

template<typename T>
int Stack<T>::size() const {  // return number of elements in the current stack
  return stk.size();
}

template <typename T>
bool operator==(const Stack<T> & lhs, const Stack<T> & rhs) {
  bool flag = true;
  if(rhs.size() != lhs.size())
    return false;
  else {
    bool flag = true;
    Stack<T> left;
    Stack<T> right;
    left = lhs;
    right = rhs;
    while(flag && !(right.empty())) {
      if(left.top() != right.top()) {
        bool flag = false;
        break;
      }
      left.pop();
      right.pop();
    }
  return flag;
  }
}

template <typename T>
bool operator!=(const Stack<T> & lhs, const Stack<T> & rhs) {
  return(!(lhs == rhs));
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const Stack<T> &a) {
  for (int i = 0; i < a.size(); ++i)
    os << a[i] << ' ';
  return os;
}
