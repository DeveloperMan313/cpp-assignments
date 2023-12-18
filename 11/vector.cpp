#include "vector.hpp"

template <typename T> vector<T>::vector() {
  this->array = new T[1];
  this->capacity = 1;
  this->size = 0;
}

template <typename T> vector<T>::~vector() { delete[] this->array; }

template <typename T> void vector<T>::resize(size_t capacity) {
  T *newArray = new T[capacity];
  size_t minSize = (this->size < capacity) ? this->size : capacity;
  for (size_t i = 0; i < minSize; ++i) {
    newArray[i] = array[i];
  }
  delete[] this->array;
  this->array = newArray;
  this->capacity = capacity;
  this->size = minSize;
}

template <typename T> void vector<T>::push(const T &element) {
  if (size == capacity) {
    this->resize(this->capacity * vecResizeFactor);
  }
  this->array[size] = element;
  ++size;
}

template <typename T> void vector<T>::clear() {
  if (this->size == 0) {
    return;
  }
  delete[] this->array;
  this->array = new T[1];
  this->capacity = 1;
  this->size = 0;
}

template <typename T> T &vector<T>::operator[](size_t i) const {
  return this->array[i];
}

template struct vector<char>;
template struct vector<char *>;
