#include "main_header.h"

void print_child(child_t child)
{
    printf("%s  ", child.name);
    printf("%s  ", child.cpr);
    printf("%d  ", child.siblings);
    for (int i = 0; i < MAX_PREFERENCES; i++)
    {
        printf("%d ", child.preferences[i]);
    }
    printf("\n");
}
