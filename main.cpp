#include <iostream>
#include "src/cutie.hpp"

int main() {
    // Create a bunch of objects that implement the Cutie base class
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    // Create a queue data structure
    QueueTees queue;

    // The size of the queue should equal zero since there are no objects in it
    std::cout << queue.size();

    // Add the cuties to the queue
    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    queue.enqueue(&marmoset);

    // The size of the queue should equal three since there are three objects in it
    std::cout << queue.size();

    // The first dequeue should return the puppy
    queue.dequeue();

    // The second dequeue should return the kitty
    queue.dequeue();

    // The third dequeue should return the pygmy marmoset
    queue.dequeue();
}
