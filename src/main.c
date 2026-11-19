#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 30

/*

    Hvis det danske ord på en kolonne indeholder æ, ø eller å, så har jeg oversat det til engelsk.
    I alle andre tilfælde står det bare på dansk :))

*/

typedef struct
{
    char placering[MAX_NAME_LENGTH];
    char navn[MAX_NAME_LENGTH];
    char adresse[MAX_NAME_LENGTH];
    int cpr;
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
    int prioritet;                 // 1 - 5 ik?
    bool specialneeds;             // har lavet det som en bool datatype med stdbool library, men kunne naturligvis også være en int

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

    char felt[100];
    char separator;
    for (int i = 0; i < 30; i++)
    {
        if (fscanf(f, "%99[^\t\r\n]%c", felt, &separator) == 2 && separator == '\t')
        {
            printf("%s\n", felt);
        }
    }
    /*
    Ovenstående implementation ^^ er fra chatten (den uintelligente for-løkke har jeg dog selv lavet),
    fordi jeg spurgte hvordan man læser fra en fil indtil næste tab/4 spaces.
    Tænker man kan lave det på en lidt bedre måde, hvor den fx læser en hel linje, indtil \t (linjeskift i tsv-filer),
    og man så kunne have en anden funktion, der skrev det til et structen? idk
    */ 

    // fscanf(f, "%s %s %s %d", child.placering, child.navn, child.adresse, child.cpr);
    return child;
}

void print_child(child_t child)
{
    printf("Placering: %s\n", child.placering);
    printf("Navn: %s\n", child.navn);
    printf("Adresse: %s\n", child.adresse);
    printf("CPR-nummer: %d\n", child.cpr);
    printf("ooog så videre, ik ogs..\n");
}

int main(void)
{
    FILE *input_file = fopen("children.tsv", "r");
    if (input_file == NULL)
    {
        printf("Error: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    child_t input_child = read_child_from_file(input_file);
    fclose(input_file);
    // print_child(input_child);

    return 0;
}