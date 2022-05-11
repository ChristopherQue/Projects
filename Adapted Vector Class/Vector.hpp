template<typename T>
Vector<T>::Vector() { // default zero parameter constructor
  theSize = 0;
  theCapacity = 0;
  array = new T[theCapacity];
  array = nullptr;
}

template<typename T>
Vector<T>::Vector(const Vector &rhs) { // copy constructor
  theSize = rhs.theSize;
  theCapacity = rhs.theCapacity;
  array = nullptr;
  array = new T[theCapacity];
  for (int i = 0; i < theSize; i++)
    array[i] = rhs.array[i];
}

template<typename T>
Vector<T>::Vector(Vector &&rhs) { // move constructor
  theSize = rhs.theSize;
  theCapacity = rhs.theCapacity;
  array = rhs.array;
  rhs.array = nullptr;
  rhs.theSize = 0;
  rhs.theCapacity = 0;
}

// num elements with value of val
template <typename T>
Vector<T>::Vector(int num, const T& val) {
  theSize = num;
  theCapacity = num;
  array = new T[theCapacity];
  for (int i = 0; i < theSize; ++i)
    array[i] = val;
}

// constructs with elements [start, end)
template<typename T>
Vector<T>::Vector(const_iterator start, const_iterator end) {
  theSize = 0;
  array = new T[theSize];
  for(auto itr = start; itr < end; ++itr)
    push_back(*itr);
}

template<typename T>
Vector<T>::~Vector() { //  destructor
  delete [] array;
}

// operators

// index operator
template <typename T>
T& Vector<T>::operator[](int index) {
  return array[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
  return array[index];
}

// copy assignment operator
template <typename T>
const Vector<T>& Vector<T>::operator= (const Vector &rhs) {
  Vector<T> copy = rhs;
  copy = *this;
  return *this;
}

// move assignment operator
template <typename T>
Vector<T> & Vector<T>::operator=(Vector &&rhs) {
  theSize = rhs.theSize;
  theCapacity = rhs.theCapacity;
  array = rhs.array;
  return *this;
}

// at function. safer than operator[]
template <typename T>
T& Vector<T>::at(int loc ) {
  if (loc < 0 || loc > theSize)
    throw "out_of_range";
  else
    return array[loc];
}

template <typename T>
const T& Vector<T>::at(int loc) const {
  if (loc < 0 || loc > theSize)
    throw "out_of_range";
  else
    return array[loc];
}

template <typename T>
T & Vector<T>::front() {
  return array[0];
}

template <typename T>
const T& Vector<T>::front() const {
  return array[0];
}

template <typename T>
T & Vector<T>::back() {
  return array[theSize-1];
}

template <typename T>
const T & Vector<T>::back() const {
  return array[theSize - 1];
}

// accessor member functions
template<typename T>
int Vector<T>::size() const { // number of elements
  return theSize;
}

template<typename T>
int Vector<T>::capacity() const { // capacity of vector
  return theCapacity;
}

template<typename T>
bool Vector<T>::empty() const { // check if list is empty
  return size() == 0;
}

// mutator member functions
template<typename T>
void Vector<T>::clear() { // delete all elements
  theSize = 0;
  theCapacity = 0;
}

template<typename T>
void Vector<T>::push_back(const T & val) { // insert to the end
  if(theSize == theCapacity)
    reserve(2 * theCapacity + 1);
  array[theSize++] = val;
}

template<typename T>
void Vector<T>::pop_back() { // delete last element
  --theSize;
}

template<typename T>
void Vector<T>::resize(int num, T val) { // resize vector
  if(theSize < num) {
    T* temp = new T[num];
    for(int i = 0; i < theSize; ++i)
      temp[i] = array[i];
    for(int j = theSize; j != num; ++j)
      temp[j] = val;
    swap(array,temp);
    temp = nullptr;
    theSize = num;
    theCapacity = num;
  }
}

template<typename T>
void Vector<T>::reserve(int newCapacity) { // reserve memory
  if(newCapacity < theSize)
    return;
  T *newArray = new T[newCapacity];
  for (int i = 0; i < theSize; i++)
    newArray[i] = array[i];
  theCapacity = newCapacity;
  std::swap(array, newArray);
  delete [] newArray;
}

// print out all elements. ofc is deliminitor
template<typename T>
void Vector<T>::print(std::ostream& os, char ofc) const {
  for (int i = 0; i < theSize; ++i)
    os << array[i] << ofc;
}

// iterator support
template<typename T>
typename Vector<T>::iterator Vector<T>::begin() { // iterator to first element
  return &array[0];
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
  return &array[0];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() { // end marker iterator
  return &array[size()];
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const {
  return &array[size()];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator itr, const T& val) { // insert val ahead of itr
  T* temp = new T[++theCapacity];
  int element = itr - begin(); // to get position for insertion

  for(int i = 0; i < element; ++i)
    temp[i] = std::move(array[i]);

  temp[element] = val; // position of insertion

  int point = end() - begin() + 1;
  for(int j = element; j != point; ++j)
    temp[j + 1] = std::move(array[j]);

  swap(temp,array);
  ++theSize;
  delete [] temp;
  return & array[element];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator itr) { // erase one element
  auto temp = itr;
  do {
    *itr = *(itr + 1);
    ++itr;
  } while(itr < end());
  --theSize;
  return temp;
}


template<typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator start, iterator end) { // erase [start, end)
  auto temp = start;
  while(erase(start) != --end)
    temp = start;
  return temp;
}

template<typename T>
void Vector<T>::doubleCapacity() {
  if (theCapacity == 0)
    theCapacity = 1;
  reserve(theCapacity * 2);
}

template <typename T>
bool operator==(const Vector<T> &lhs, const Vector<T> &rhs) {
  if(lhs.size() != rhs.size())
    return false;
  else {
    int j = 0;
    int temp = 0;
    for(int i = 0; i < lhs.size(); ++i) {
      if (lhs[i] == rhs[i])
      ++j;
      temp = i;
    }
    if(temp == j)
      return false;
    return true;
  }
}

template <typename T>
bool operator!=(const Vector<T> &lhs, const Vector<T> &rhs) {
  if (lhs != rhs)
    return true;
  return false;
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const Vector<T> &v) {
  for (int i = 0; i < v.size(); ++i)
    os << v[i] << ' ';
  return os;
}
