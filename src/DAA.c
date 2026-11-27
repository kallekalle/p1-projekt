#include "main_header.h"

void accept_or_reject (child_t prop_child, child_t lowest_rank_child, institution_t institution) {
    if (institution.capacity - institution.assigned_count > 0) {
        // Assign proposing child to the institution via index
        prop_child.assigned = institution.index;
        institution.assigned_count++;
    }
    else if (prop_child.rank > lowest_rank_child.rank){
        // Unassign the lowest ranked child and assign proposing child instead
        lowest_rank_child.assigned = -1;
        prop_child.assigned = institution.index;
    } else {
       // Don't do anything - Rejecting proposing child
    }
}
