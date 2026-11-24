#include "HeaderFile.h"

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
                        "%63[^\t\r\n]%*1[\t]%10[0-9]%*1[\t]%d%*1[\t]"
                        "%d%*1[\t]%d%*1[\t]%d%*1[\t]%d%*1[\t]%d",
                        child.name, child.cpr, &child.siblings,
                        &child.preferences[0], &child.preferences[1], &child.preferences[2],
                        &child.preferences[3], &child.preferences[4]);

    if (fields != 8)
    {
        fprintf(stderr, "Kunne ikke læse alle felter for barnet\n");
        exit(EXIT_FAILURE);
    }
    return child;
    // Jeg tror ikke denne returnerede funktionsværdi bruges til noget i funktionskaldet i main.. måske lige undersøge det nærmere
}
