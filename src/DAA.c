#include "main_header.h"

void accept_or_reject (child_t child, child_t lowest_ranked_child, institution_t institution) {
    if (institution.capacity != 0) {
        // Assign the child to the institution via index
        child.assigned = institution.index;
        // Decrease capacity by 1
        institution.assigned_count++;
    } else if (institution.capacity == 0 && child.rank > lowest_ranked_child.rank){
        // Unassign the lowest ranked child
        lowest_ranked_child.assigned = -1;
        child.assigned = institution.index;
    } else {
       // Don't do anything
    }
}