/* This library is to contain all libraries used throughout our allocation program collected in one file
 * It also contains our structs. It should tie all our different functions together.
 */

#ifndef P1_PROJEKT_HEADERFILE_H
#define P1_PROJEKT_HEADERFILE_H

#define MAX_NAME_LENGTH 64
#define MAX_CHILDREN 1000
#define MAX_CAPACITY 200
#define MAX_PREFERENCES 5
#define MAX_ID_PLUS_TWO 12
#define NUMBER_OF_CHILDREN 1000 // It needs to be loaded from the file.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Makes it possible to print æøå in the terminal
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef _WIN32
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);
#endif

/* Struct for each child registered for allocation */
typedef struct
{
    char name[MAX_NAME_LENGTH];
    char cpr[MAX_ID_PLUS_TWO]; // 10 cifre + '\0'. char frem for int, fordi evt. foranstillede nuller (fx 060403-3123) skal medtages. hvis man indlæser det som en int, så forsvinder de.
    int siblings;              // Institution index, or -1 if the child has no siblings in an institution.
    int preferences[MAX_PREFERENCES];
    int next_choice;
    bool specialneeds; // True or false, doesn't say to what degree
    int application_date;
    int assigned;
} child_t;

typedef struct
{
    int index;
    char name[MAX_NAME_LENGTH];
    int capacity;
    int assigned[MAX_CAPACITY];
    int assigned_count;
    int number_of_ranked;
    child_t point[NUMBER_OF_CHILDREN];   // How many points each child gets
    child_t ranking[NUMBER_OF_CHILDREN]; // This is the institution priority list of the children
} institution_t;

/* Function prototypes below here */
child_t tiebreaker(child_t child1, child_t child2);
void accept_or_reject(child_t child, child_t lowestrankedchild, institution_t institution);
FILE *file_choice();
child_t read_child_from_file(FILE *f);
void print_child(child_t child);
void institution_list_child(institution_t institutions[], int number_of_institutions, const child_t child[], int number_of_children);

#endif // P1_PROJEKT_HEADERFILE_H
