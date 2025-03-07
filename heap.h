#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;


  T& operator[](size_t index);

private:
  /// Add whatever helper functions and data members you need below
    std::vector<T> heap;
    int m;
    PComparator comparator;

   void heapifyUp(size_t index);
   void heapifyDown(size_t index);

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c ){

}

template <typename T, typename PComparator>
Heap<T, PComparator>:: ~Heap() {
  

}

template <typename T, typename PComparator>
  bool Heap<T, PComparator>::empty() const{
    return heap.size() ==0;
  }

template <typename T, typename PComparator >
void Heap<T, PComparator>::push(const T& item) {
    heap.push_back(item);
    heapifyUp(heap.size() - 1);
}

template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const {
    if (empty()) {
        throw std::underflow_error("Error");
    }
    return heap.front();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
    if (empty()) {
        throw std::underflow_error("Error");
    }
    T temp = heap.front();
    heap.front() = heap.back();
    heap.back() = temp;
    heap.pop_back();
    heapifyDown(0);
  
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index) {
    while (index > 0) {
        int parentIndex = (index - 1) / m;
        if (!comparator(heap[parentIndex], heap[index])) {
           // std::cout << "Swapping elements at indices " << parentIndex << " and " << index << std::endl;
            T temp = heap[parentIndex];
            heap[parentIndex] = heap[index];
            heap[index] = temp;
            index = parentIndex;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index) {
    while (true) {
        int largestChild = index;
        for (size_t i = 1; i <= m && index * m + i < heap.size(); ++i) {
            if (comparator(heap[index * m + i], heap[largestChild])) {
                largestChild = index * m + i;
            }
        }

        if (largestChild != index) {
           // std::cout << "Swapping elements at indices " << index << " and " << largest << std::endl;
            T temp = heap[index];
             heap[index] = heap[largestChild];
             heap[largestChild] = temp;
            index = largestChild;
        } else {
            break;
        }
    }
}


template <typename T, typename PComparator>
T& Heap<T, PComparator>::operator[](size_t index) {
  if (index >= heap.size()) {
    throw std::out_of_range("Index out of range");
  }
  return heap[index];
}
#endif

