#include "heap.h"

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : heap(), m(m), comparator(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}
