#include "HeaderFile.h"


child_t Tiebreaker(child_t child1, child_t child2) {
    srand(time(NULL));
    int child1value;
    int child2value;

    do {
        child1value = rand() % 9;
        child2value = rand() % 9;
    } while (child1value == child2value);
    //Test output
    printf("child1value = %d", child1value);
    printf("child2value = %d", child2value);

    if (child1value > child2value) {
        return child1;
    } // (child2value > child1value)
    return child2;
}