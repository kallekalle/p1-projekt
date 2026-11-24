#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeaderFile.h"

    //for this to work we need to make a child struct with point and cpr so we can refer to it as child[i].point, and cpr

#define NUMBER_OF_CHILDREN 1000 // It needs to be loaded from the file.

typedef struct { //headerfile.h mangler en childt_t ranking[NUMBER_OF_CHILDREN]
    char name[MAX_NAME_LENGTH];
    child_t ranking[NUMBER_OF_CHILDREN];
    int number_of_ranked;
} InstitutionList;


void InstitutionListChild(InstitutionList Institutions[], int number_of_institutions, const child_t child[], int number_of_children) {
    for (int k = 0; k < number_of_institutions; k++) {
        Institutions[k].number_of_ranked = 0;
        //i delen under bliver barn nr. i kopieret over i institutionens liste
        for (int i = 0; i < number_of_children; i++) {
            int r = Institutions[k].number_of_ranked;

            Institutions[k].ranking[r] = child[i];
            Institutions[k].number_of_ranked++;
        }
        for (int round = 0; round < Institutions[k].number_of_ranked - 1; round++) {
            for (int a = 0; a < Institutions[k].number_of_ranked - 1 - round; a++) {
                int b = a + 1;
                
                if (Institutions[k].ranking[b].point > Institutions[k].ranking[a].point) {
                    child_t temp = Institutions[k].ranking[a];
                    Institutions[k].ranking[a] = Institutions[k].ranking[b];
                    Institutions[k].ranking[b] = temp;
                }

                else if (Institutions[k].ranking[b].point == Institutions[k].ranking[a].point) {
                    child_t child_1 = Institutions[k].ranking[a];
                    child_t child_2 = Institutions[k].ranking[b];

                    child_t vinder = Tiebreaker(child_1, child_2);

                    if (strcmp(vinder.cpr, child_1.cpr) == 0) {
                        //If child_1 wins nothing happens because the function does that already, 
                    } else { //here the exactly same happens as in "if (Institutions[k].ranking[b].point > Institutions[k].ranking[a].point)"
                    child_t temp = Institutions[k].ranking[a];
                    Institutions[k].ranking[a] = Institutions[k].ranking[b];
                    Institutions[k].ranking[b] = temp;
                    }
                }
            }
        }
    }
}