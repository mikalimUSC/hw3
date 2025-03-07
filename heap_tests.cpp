#include "heap.h"
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    Heap<int> myHeap;  // Create a max-heap with default settings (ary-ness of 2)

    
    for (int i = 0; i < 50; ++i) {
        int value = rand() % 1000;  // Generate a random number between 0 and 999
       std::cout << " Pushed " << value<< std::endl;
        myHeap.push(value);
    }

    std::cout << "Top element of the heap: " << myHeap.top() << std::endl;

    // Verify that the heap is correctly organized by popping elements
    // The top element should always be the largest (or smallest, depending on the comparator)
    for (int i = 0; i < 50; ++i) {
        int topElement = myHeap.top();
        myHeap.pop();
        std::cout << "Popped: " << topElement << std::endl;
    }

    if (myHeap.empty()) {
        std::cout << "The heap is empty after popping all elements." << std::endl;
    } else {
        std::cout << "The heap is not empty after popping all elements." << std::endl;
    }

    return 0;
}
