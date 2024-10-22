#include "Pony.hpp"
#include <iostream>

void ponyOnTheHeap() {
    Pony* heapPony = new Pony("HeapPony", 5);
    heapPony->doStuff();
    delete heapPony; 
}

void ponyOnTheStack() {
    Pony stackPony("StackPony", 3);
    stackPony.doStuff();
}

int main() {
    std::cout << "Creating Pony on the heap:" << std::endl;
    ponyOnTheHeap();

    std::cout << "\nCreating Pony on the stack:" << std::endl;
    ponyOnTheStack();

    return 0;
}
