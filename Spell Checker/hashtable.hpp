// hastable.hpp

using namespace std;

// ***** Public Functions ******

template <typename T>
HashTable<T>::HashTable(size_t size) {
  currSize = 0;
  table.resize(prime_below(size));
}

template <typename T>
HashTable<T>::~HashTable() {
  clear();
}

template <typename T>
bool HashTable<T>::contains(const T& x) {
  auto& list = table[myhash(x)];
  return find(list.begin(), list.end(), x) != list.end();
}

template <typename T>
bool HashTable<T>::insert(const T & x) {
  auto& lst = table[myhash(x)];
  if(contains(x))
    return false;  // so there are no duplicate elements
  lst.push_back(x);  // inserts if it is unique
  ++currSize;  // increments size
  if(currSize > table.size())  // adjusts the hash if new size is bigger than current
    rehash();
  return true;
}

template <typename T>
bool HashTable<T>::insert(T &&x) {
  auto& lst = table[myhash(x)];
  if(contains(x))
    return false;
  lst.push_back(std::move(x));
  ++currSize;
  if(currSize > table.size())
    rehash();
}

template <typename T>
bool HashTable<T>::remove(const T &x) {
  if(!contains(x))
    return false;
  auto& lst = table[myhash(x)];
  auto itr = find(lst.begin(), lst.end(), x);
  lst.erase(itr);
  --currSize;
  return true;
}

template <typename T>
void HashTable<T>::clear() {
  makeEmpty();
}

template <typename T>
bool HashTable<T>::load(const char *filename) {
  ifstream file(filename);
  string oneLine;
  while(getline(file, oneLine)) {
    istringstream iss(oneLine);
    T element;
    iss >> element;
    insert(element);
  }
}

template <typename T>
void HashTable<T>::dump() { 
  int inc = 0;
  if(currSize != 0) {
    for(auto& lst:table) {
      for(auto itr = lst.begin(); itr != lst.end(); ++itr)
        cout << "v[" << inc++ << "]: " << *itr << endl;
    }
  }
}

template <typename T>
bool HashTable<T>::write_to_file(const char *filename) {
  // I was not able to successfully implement this function
}

template <typename T>
int HashTable<T>::getSize() const {
  return currSize;
}

// ****** Private Functions *******

template <typename T>
void HashTable<T>::makeEmpty() {
  if(currSize == 0)
    return;
  for(int i = 0; i < table.size(); ++i)
    table[i].clear();
}

template <typename T>
void HashTable<T>::rehash() {
  vector<list<T>> newTable(prime_below(2 * currSize));
  for(int i = 0; i < table.size(); ++i)
    newTable.push_back(move(table[i]));
  swap(newTable, table);
}

template <typename T>
size_t HashTable<T>::myhash(const T &x) {
  static hash<T> hash;
  return hash(x) % table.size();
}

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename T>
unsigned long HashTable<T>::prime_below (unsigned long n)
{
  if (n > max_prime)
    {
      std::cerr << "** input too large for prime_below()\n";
      return 0;
    }
  if (n == max_prime)
    {
      return max_prime;
    }
  if (n <= 1)
    {
		std::cerr << "** input too small \n";
      return 0;
    }

  // now: 2 <= n < max_prime
  std::vector <unsigned long> v (n+1);
  setPrimes(v);
  while (n > 2)
    {
      if (v[n] == 1)
	return n;
      --n;
    }

  return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n)
template <typename T>
void HashTable<T>::setPrimes(std::vector<unsigned long>& vprimes)
{
  int i = 0;
  int j = 0;

  vprimes[0] = 0;
  vprimes[1] = 0;
  int n = vprimes.capacity();

  for (i = 2; i < n; ++i)
    vprimes[i] = 1;

  for( i = 2; i*i < n; ++i)
    {
      if (vprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
          vprimes[j] = 0;
    }
}
