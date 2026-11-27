#include "main_header.h"

child_t read_child_from_file(FILE *f)
{
    child_t child;
    char line[1024];

    /* Checks if the next line in children.tsv is NULL - if it is,
    * it then prints an error message and exits.
    * When this if-statement is evaluated, the variable 'line' already
    * gets assigned the contents of the file. Therefore we can sscanf
    * directly on 'line' thereafter, and assign the data to the other
    * variables.
    */

    if (fgets(line, sizeof line, f) == NULL)
    {
        printf("Kunne ikke læse næste række fra children.tsv\n");
        exit(EXIT_FAILURE);
    }

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
    return child; // THIS RETURN VALUE IS CURRENTLY UNUSED.. MAYBE THIS SHOULD BE A VOID FUNCTION INSTEAD?
}
