#include "HeaderFile.h"


child_t Tiebreaker(child_t child1, child_t child2) {
    srand(time(NULL));
    // Makes randomvalue which will be given value 0 or 1
    int randomvalue = rand() % 2;

    // randomvalue determines which child is returned from the function.
    // We have to decide if the child returned is the one that loses or keeps their spot.
    if (randomvalue == 0) {
        // Test output
        printf("Chose child1");
        return child1;
    } // (randomvalue == 1)
    // Test output
    printf("Chose child2");
    return child2;
}