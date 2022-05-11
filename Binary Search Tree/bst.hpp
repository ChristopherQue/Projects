// bst.hpp

using namespace std;

template<typename T>
BST<T>::BST(int th) {
  root = nullptr;
  threshold = th;
}

template<typename T>
BST<T>::BST(const string input, int th) {  // constructor
  root = nullptr;
  threshold = th;
  buildFromInputString(input);
}

template<typename T>
BST<T>::BST(const BST& v) {  // copy constructor
  root = nullptr;
  root = clone(v.root);
}

template<typename T>  // move constructor
BST<T>::BST(BST&& v) {
  root = v.root;
  threshold = v.threshold;
  v.root = nullptr;
  v.threshold = 0;
}

template<typename T>
BST<T>::~BST(){  // destructor
  makeEmpty(root);
}

template<typename T>
void BST<T>::buildFromInputString(const string input) {
  makeEmpty(root);
  if(empty()) {
    stringstream iss(input);
    T inpt;
    while (iss >> inpt)
      insert(inpt);
  }
}

template<typename T>
const BST<T> & BST<T>::operator=(const BST & n) {
  if(this != &n) {
    makeEmpty();
    this->root = clone(n.root);
  }
  return *this;
}

template<typename T>
const BST<T> & BST<T>::operator=(BST<T> && n) {
  if(this != &n) {
    makeEmpty();
    std::swap(root, n.root);
    n.root = nullptr;
  }
  return *this;
}

template<typename T>
bool BST<T>::empty() {
  return(root == nullptr);
}

template<typename T>
void BST<T>::printInOrder() const {
  printInOrder(root);
  cout << endl;
}

template<typename T>
void BST<T>::printLevelOrder() const {
  printLevelOrder(root);
}

template<typename T>
int BST<T>::numOfNodes() const {
  return numOfNodes(root);
}

template<typename T>
int BST<T>::height() const {
  return height(root);
}

template<typename T>
void BST<T>::makeEmpty() {
  makeEmpty(root);
}

template<typename T>
void BST<T>::insert(const T& v) {
  insert(v, root);
}

template<typename T>
void BST<T>::insert(T &&v) {
  insert(std::move(v),root);
}

template<typename T>
void BST<T>::remove(const T& v) {
  remove(v, root);
}

template<typename T>
bool BST<T>::contains(const T& v) {
  if(v == root->element) {
    root->counter = 0;
    return true;
  }
  else if(v < root->element)
    return contains(v, root->left, root);
  else
    return contains(v, root->right, root);
}

// private functions
template<typename T>
typename BST<T>::BSTNode* BST<T>::clone(BST<T>::BSTNode* t)const {
  if(t == nullptr)
    return nullptr;
  else
    return new BSTNode(t->element, clone(t->left), clone(t->right));
}

template<typename T>
void BST<T>::printInOrder(BSTNode *t) const {
  if(t != nullptr) {
    printInOrder(t->left);
    cout << t->element << " ";
    printInOrder(t->right);
  }
}

template<typename T>
void BST<T>::printLevelOrder(BSTNode *t) const {  // does not need to be recursive
  if(t == nullptr)
    return;
  queue<BSTNode*> print;
  print.push(t);
  while (!print.empty()) {
    BSTNode* front = print.front();
    cout << front->element << " ";
    if(front->left != nullptr)
      print.push(front->left);
    if(front->right != nullptr)
      print.push(front->right);
    print.pop();
  }
  cout << endl;
}

template<typename T>
void BST<T>::makeEmpty(BSTNode* &t) {
  if(t != nullptr) {
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
  }
  t = nullptr;
}

template<typename T>
void BST<T>::insert(const T& v, BST<T>::BSTNode *&t) {
  // slide 14 ch4_tree3 powerpoint
  if(t == nullptr)
    t = new BSTNode{v, nullptr, nullptr};
  else if(v < t->element)
    insert(v, t->left);
  else if(t->element < v)
    insert(v, t->right);
  else
    ; // event of a duplicate
}

template<typename T>
void BST<T>::insert(T&& v, BSTNode *&t) {
    if(t == nullptr)
      t = new BSTNode{std::move(v), nullptr, nullptr};
    else if(v < t->element)
      insert(std::move(v), t->left);
    else if(v > t->element);
      insert(std::move(v), t->right);
}

template<typename T>
void BST<T>::remove(const T& v, BSTNode *&t) {
  // slide 17 ch4_tree3
  if(t == nullptr)
    return; // if item is not found
  if(v < t->element)
    remove(v, t->left);
  else if(t->element < v)
    remove(v, t->right);
  else if(t->left != nullptr && t->right != nullptr) {  // two children
    t->element = min(t->right)->element;
    remove(t->element, t->right);
  }
  else {
    BSTNode *oldNode = t;
    t = (t->left != nullptr) ? t->left: t->right;
    delete oldNode;
  }
}

template<typename T>
bool BST<T>::contains(const T& v, BSTNode *&t, BSTNode *& w) {
  if(t == nullptr)
    return false;
  if(v < t->element)
    return contains(v, t->left, t);
  else if(v > t->element)
    return contains(v, t->right, t);
  else {
    ++ (t->counter);
    if (t->counter > threshold) {
      if (t == w->left) {
        BSTNode * oldnode = w;
        w = t;
        oldnode->left = t->right;
        w->right = oldnode;
      }
      else if (t == w->right) {
        BSTNode * oldnode = w;
        w = t;
        oldnode->right = t->left;
        w->left = oldnode;
      }
      t->counter = 0;
      return true;
    }
  }
}

template<typename T>
int BST<T>::numOfNodes(BSTNode *t) const {
  if(t == nullptr)
    return 0;
  return numOfNodes(t->left) + numOfNodes(t->right) + 1;
}

template<typename T>
int BST<T>::height(BSTNode *t)const {
  int rightHeight, leftHeight;
  if(t == nullptr)
    leftHeight = rightHeight = 0;
  else {
    leftHeight = height(t->left) + 1;
    rightHeight = height(t->right) + 1;
  }
  if(leftHeight > rightHeight)
    return leftHeight;
  else
    return rightHeight;
}

template<typename T>
typename BST<T>::BSTNode* BST<T>::clone(BST<T>::BSTNode *t) {
  if(t == nullptr)
    return nullptr;
  else
    return new BSTNode(t->element, clone(t->left), clone(t->right));
}

template <typename T>
typename BST<T>::BSTNode * BST<T>::min(BSTNode * t ) const // funciton to func minimum value
{
	if( t == nullptr )
		return nullptr;
	if( t->left == nullptr )
		return t;
	return min(t->left);
}
