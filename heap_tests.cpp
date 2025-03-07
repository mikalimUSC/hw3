#include "heap.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    Heap<int> myHeap;  
    
    for (int i = 0; i < 50; ++i) {
        int value = rand() % 1000; 
       std::cout << " Pushed " << value<< std::endl;
        myHeap.push(value);
    }

    std::cout << "Top element of the heap: " << myHeap.top() << std::endl;
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
