#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../src/cutie.hpp"

TEST_CASE( "initial size is empty" ) {
    QueueTees queue;
    REQUIRE( queue.size() == 0 );
}

TEST_CASE( "can enqueue and dequeue a Puppy" ) {
    QueueTees queue;
    Puppy puppy;
    queue.enqueue(&puppy);
    REQUIRE( queue.size() == 1 );
    Cutie *dequeued_cutie = queue.dequeue();
    REQUIRE( puppy.get_description() == dequeued_cutie->get_description());
    REQUIRE( queue.size() == 0 );
}

TEST_CASE( "can enqueue and dequeue multiple Cuties" ) {
    QueueTees queue;
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;
    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    queue.enqueue(&marmoset);
    REQUIRE( queue.size() == 3 );
    Cutie *dequeued_cutie = queue.dequeue();
    REQUIRE( puppy.get_description() == dequeued_cutie->get_description());
    REQUIRE( queue.size() == 2 );
}

TEST_CASE( "can enqueue and check cuteness of multiple Cuties" ) {
    QueueTees queue;
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;
    queue.enqueue(&marmoset);
    queue.enqueue(&kitty);
    queue.enqueue(&puppy);
    REQUIRE( queue.size() == 3 );
    Cutie *dequeued_cutie1 = queue.dequeue();
    Cutie *dequeued_cutie2 = queue.dequeue();
    REQUIRE( dequeued_cutie2->get_cuteness_rating() < dequeued_cutie1->get_cuteness_rating());
    REQUIRE( queue.size() == 1 );
}

TEST_CASE( "can add max Cuties" ) {
    QueueTees queue;
    Puppy test_puppy;
    for (int i = 0; i < queue.getMaxSize(); i++) {
        queue.enqueue(&test_puppy);
    }
    REQUIRE(queue.size() == queue.getMaxSize());
}
