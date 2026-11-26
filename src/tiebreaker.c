#include "main_header.h"


child_t tiebreaker(child_t child1, child_t child2) {
    srand(time(NULL));
    // Makes randomvalue which will be given value 0 or 1
    int random_value = rand() % 2;

    // randomvalue determines which child is returned from the function.
    // The child returned is the one that gets the spot.
    if (random_value == 0) {
        // Test output
        printf("Chose child1");
        return child1;
    } // (randomvalue == 1)
    // Test output
    printf("Chose child2");
    return child2;
}