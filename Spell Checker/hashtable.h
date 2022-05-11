// hastable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

namespace cop4530 {

  // used when improper size is given (for example
  // size is 0 or negatiave)
  static const unsigned int default_capacity = 11;
  static const unsigned int max_prime = 1301081;


  template <typename T>
  class HashTable {
    public:
      HashTable(size_t size = 101);
      ~HashTable();
      bool contains(const T &x);
      bool insert(const T & x);
      bool insert(T &&x);
      bool remove(const T &x);
      void clear();
      bool load(const char *filename);
      void dump();
      bool write_to_file(const char *filename);
      int getSize() const;

    private:
      int currSize;
      void rehash();
      void makeEmpty();
      size_t myhash(const T &x);
      unsigned long prime_below(unsigned long);
      void setPrimes(std::vector<unsigned long> &);
      vector<std::list<T>> table;
};

#include "hashtable.hpp"
}
#endif
