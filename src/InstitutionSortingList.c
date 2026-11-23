#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HeaderFile.h"

#define MAX_RANKED_PER_INST 1000

typedef struct { //dette er det jeg har gået ud fra er måden vi alver institutioner på
    char navn[MAX_NAME_LENGTH];
    child_t rangeret[MAX_RANKED_PER_INST];
    int antal_rangeret;
} InstitutionListe;


void InstitutionListChild(InstitutionListe Institutioner[], int antal_institutions, const child_t child[], int antal_children) {
    for (int k = 0; k < antal_institutions; k++) {
        Institutioner[k].antal_rangeret = 0;
        //i delen under bliver barn nr. i kopieret over i institutionens liste
        for (int i = 0; i < antal_children; i++) {
            int r = Institutioner[k].antal_rangeret;

                Institutioner[k].rangeret[r] = child[i];
                Institutioner[k].rangeret[r].point = child[i].point;
                Institutioner[k].antal_rangeret = Institutioner[k].antal_rangeret + 1;
        }
        for (int runde = 0; runde < Institutioner[k].antal_rangeret - 1; runde++) {
            for (int a = 0; a < Institutioner[k].antal_rangeret - 1 - runde; a++) {
                int b = a + 1;

                if (Institutioner[k].rangeret[b].point > Institutioner[k].rangeret[a].point) {
                    child_t temp = Institutioner[k].rangeret[a];
                    Institutioner[k].rangeret[a] = Institutioner[k].rangeret[b];
                    Institutioner[k].rangeret[b] = temp;
                }

                if (Institutioner[k].rangeret[b].point == Institutioner[k].rangeret[a].point) {
                    child_t child_1 = Institutioner[k].rangeret[a];
                    child_t child_2 = Institutioner[k].rangeret[b];

                    child_t vinder = Tiebreaker(child_1, child_2){

                    if (strcmp(vinder.cpr, child_1.cpr) == 0) {
                        taber = child_2;
                    } else {
                    child_t temp = Institutioner[k].rangeret[a];
                    Institutioner[k].rangeret[a] = Institutioner[k].rangeret[b];
                    Institutioner[k].rangeret[b] = temp;
                    }
                }
            }
        }
    }
}
