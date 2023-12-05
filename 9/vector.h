#pragma once

#include <cstddef>

const size_t vecResizeFactor = 2;

template <typename T> struct vector {
  T *array;
  size_t capacity;
  size_t size;

  vector();

  ~vector();

  void resize(size_t capacity);

  void push(const T &element);

  T &operator[](size_t i) const;
};
