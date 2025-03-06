#include <iostream>
#include "heap.h"


int main() {
    
    Heap<int> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(15);

    std::cout << "Top element: " << minHeap.top() << std::endl;  // Output should be 5

    return 0;
}