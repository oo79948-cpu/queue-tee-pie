#include "cutie.hpp"
#include <stdexcept>

void QueueTees::enqueue(Cutie *cutie) {
    if (index >= getMaxSize() - 1) {
        throw std::out_of_range("Out of range");
    }
    index++;
    cuties[index] = cutie;
}

Cutie *QueueTees::dequeue() {
    if (index < 0) {
        throw std::out_of_range("There are no cuties to dequeue");
    }
    Cutie *temp_cutie = cuties[0];
    for (int i = 0; i < getMaxSize() - 1; i++) {
        cuties[i] = cuties[i + 1];
    }
    index--;
    return temp_cutie;
}

int QueueTees::size() {
    return index + 1;
}
