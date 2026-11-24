/* This library is to contain all libraries used throughout our allocation program collected in one file
 * It also contains our structs. It should tie all our different functions together.
 */

#ifndef P1_PROJEKT_HEADERFILE_H
#define P1_PROJEKT_HEADERFILE_H
#endif //P1_PROJEKT_HEADERFILE_H

#define MAX_NAME_LENGTH 64
#define MAX_CHILDREN 1000
#define MAX_CAPACITY 200

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Include time.h for random function
#include <time.h>

/* Struct for each child registered for allocation */
typedef struct
{
    char navn[MAX_NAME_LENGTH];
    int cpr[MAX_NAME_LENGTH];
    bool siblings;                       // lidt usikker på om det her skal være antal søskende eller boolean
    int prioritet1;
    int prioritet2;
    int prioritet3;
    int prioritet4;
    int prioritet5;
    bool specialneeds; // har lavet det som en bool datatype med stdbool library, men kunne naturligvis også være en int
    int application_date; // hvornår har barnet/forældrene ansøgt.. kunne måske være brugbar
    int assigned;
} child_t;

typedef struct {
    int index;
    char name[MAX_NAME_LENGTH];
    int capacity;

    int ranking[MAX_CHILDREN];
    int ranking_count;

    int assigned[MAX_CAPACITY];
    int assigned_count;
} institution_t;

/* Functions below here */
child_t Tiebreaker(child_t child1, child_t child2);
void AcceptOrReject (child_t child, child_t lowestrankedchild, institution_t institution);