#include "main_header.h"

void institution_list_child(institution_t institutions[], int number_of_institutions, const child_t child[], int number_of_children)
{
    for (int k = 0; k < number_of_institutions; k++)
    {
        institutions[k].number_of_ranked = 0;
        // In the part below, child index 'i' gets copied in to institution 'i's list
        for (int i = 0; i < number_of_children; i++)
        {
            int r = institutions[k].number_of_ranked;

            institutions[k].ranking[r] = child[i];
            institutions[k].number_of_ranked++;
        }
        for (int round = 0; round < institutions[k].number_of_ranked - 1; round++)
        {
            for (int a = 0; a < institutions[k].number_of_ranked - 1 - round; a++)
            {
                int b = a + 1;

                if (institutions[k].ranking[b].point > institutions[k].ranking[a].point)
                {
                    child_t temp = institutions[k].ranking[a];
                    institutions[k].ranking[a] = institutions[k].ranking[b];
                    institutions[k].ranking[b] = temp;
                }

                else if (institutions[k].ranking[b].point == institutions[k].ranking[a].point)
                {
                    child_t child_1 = institutions[k].ranking[a];
                    child_t child_2 = institutions[k].ranking[b];

                    child_t winner = tiebreaker(child_1, child_2);

                    if (strcmp(winner.cpr, child_1.cpr) != 0)
                    {
                        // If child 2 wins, then child 2 has to be ranked before child 1
                        child_t temp = institutions[k].ranking[a];
                        institutions[k].ranking[a] = institutions[k].ranking[b];
                        institutions[k].ranking[b] = temp;
                    }
                }
            }
        }
    }
}