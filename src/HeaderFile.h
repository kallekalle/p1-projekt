/* This library is to contain all libraries used throughout our allocation program collected in one file
 * It also contains our structs. It should tie all our different functions together.
 */

#ifndef P1_PROJEKT_HEADERFILE_H
#define P1_PROJEKT_HEADERFILE_H
#endif //P1_PROJEKT_HEADERFILE_H

#define MAX_NAME_LENGTH 64

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Include time.h for random function
#include <time.h>

/* Struct for each child registered for allocation */
typedef struct
{
    char placering[MAX_NAME_LENGTH];
    char navn[MAX_NAME_LENGTH];
    char adresse[MAX_NAME_LENGTH];
    char cpr[MAX_NAME_LENGTH];
    int birth; // skal den her sløjfes? vi har jo cpr
    int behovsdato;
    int siblings;                       // lidt usikker på om det her skal være antal søskende eller boolean
    char aldersgruppe[MAX_NAME_LENGTH]; // forestiller mig det her skal være institutionstype, fx BØRNEHAVE, VUGGESTUE, DAGPLEJE. måske man skulle indføre en enum eller lignende.. måske noget const enum aldersgruppe aldersgrupper[] = {VUGGESTUE, DAGPLEJE, BOERNEHAVE};
    char tilbud[MAX_NAME_LENGTH];       // måske lidt det samme som ovenstående.. datasættet fra chatgpt har enten "sendt" eller "accepteret alternativ" som data i denne kolonne
    int alder;                          // skal nok være i måneder
    int slutdato;
    char modul[MAX_NAME_LENGTH];   // her enten "fuldtid" eller "deltid 30 timer". man kunne også lave den som en int med 37 eller 30 (timer) som data, måske det er nemmere idk
    int garantidato;               // antager det her er "barnet SKAL have en plads inden denne dato"
    char notater[MAX_NAME_LENGTH]; // tror ikke vi får brug for den her
    char prioritet1[MAX_NAME_LENGTH];
    char prioritet2[MAX_NAME_LENGTH];
    char prioritet3[MAX_NAME_LENGTH];
    char prioritet4[MAX_NAME_LENGTH];
    char prioritet5[MAX_NAME_LENGTH];
    bool specialneeds; // har lavet det som en bool datatype med stdbool library, men kunne naturligvis også være en int

    // OBS: nedenstående er formentligt unødvendige.. i må lige vurdere hvad I synes
    char institution[MAX_NAME_LENGTH]; // lidt usikker på hvad den her dækker over.. spørg chat
    char skoledistrikt[MAX_NAME_LENGTH];
    char betaler[MAX_NAME_LENGTH];
    char anden_kommune[MAX_NAME_LENGTH];
    char current_institution[MAX_NAME_LENGTH];
    int fremtidig_indmeldelse;
    int changed;          // hvornår blev dette barns "egenskaber" sidst ændret, tror jeg.
    int changed_by;       // hvem har foretaget ændringerne
    int application_date; // hvornår har barnet/forældrene ansøgt.. kunne måske være brugbar
} child_t;