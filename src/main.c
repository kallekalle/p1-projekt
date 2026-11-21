#include "HeaderFile.h"
/*

    Hvis det danske ord på en kolonne indeholder æ, ø eller å, så har jeg oversat det til engelsk.
    I alle andre tilfælde står det bare på dansk :)):)

*/



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
