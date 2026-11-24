#include "HeaderFile.h"

void AcceptOrReject (child_t child, child_t lowestrankedchild, institution_t institution) {
    if (institution.capacity != 0) {
        // Assign the child to the institution via index
        child.assigned = institution.index;
        // Decrease capacity by 1
        institution.assigned_count++;
    } else if (institution.capacity == 0 && child.rank > lowestrankedchild.rank){
        // Unassign the lowest ranked child
        lowestrankedchild.assigned = -1;
        child.assigned = institution.index;
    } else {
       // Don't do anything
    }
}