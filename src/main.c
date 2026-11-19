#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 64

/*

    Hvis det danske ord på en kolonne indeholder æ, ø eller å, så har jeg oversat det til engelsk.
    I alle andre tilfælde står det bare på dansk :)):)

*/

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

child_t read_child_from_file(FILE *f)
{
    child_t child;
    char line[1024];

    if (fgets(line, sizeof line, f) == NULL)
    {
        printf("Kunne ikke læse næste række fra children.tsv\n");
        exit(EXIT_FAILURE);
    }
    // Vi har erklæret char-arrayet line; vi tjekker herefter med fgets
    // om næste linje i filen f er NULL, hvis den er det, så exit

    int fields = sscanf(line,
                        "%29[^\t\r\n]%*1[\t]%29[^\t\r\n]%*1[\t]"
                        "%63[^\t\r\n]%*1[\t]%15[^\t\r\n]",
                        child.placering, child.navn, child.adresse, child.cpr);
    /*
    sscanf læser de første fire felter og lægger dem ind i child-structen
    (hvis vi senere hen finder ud af, at vi skal læse flere kolonner, så kan det naturligvis opdateres)
    Grunden til vi ikke bruger fscanf længere, er fordi den ikke automatisk positionen i filen videre til næste række,
    så ved næste kald ville den være på samme række
    sscanf rykker den automatisk videre.
    */

    return child;
    // Jeg tror ikke denne returnerede funktionsværdi bruges til noget i funktionskaldet i main.. måske lige undersøge det nærmere
}

void print_child(child_t child)
{
    printf("%s  ", child.placering);
    printf("%s  ", child.navn);
    printf("%s  ", child.adresse);
    printf("%s  \n", child.cpr);
}

int main(void)
{
    FILE *input_file = fopen("children.tsv", "r");
    if (input_file == NULL)
    {
        printf("Error: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    /*
    skal man her implementere en for-løkke,
    der kender antallet af børn i filen (i < size)
    og printer dem alle? i stedet for der skal
    oprettes og printes 50 "manuelle" børn?
    */
    child_t input_child = read_child_from_file(input_file);
    child_t another_child = read_child_from_file(input_file);

    fclose(input_file);

    print_child(input_child);
    print_child(another_child);

    return 0;
}
