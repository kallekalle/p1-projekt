#include "HeaderFile.h"

int main(void)
{
    FILE *input_file = Filechoice();

    // en enkelt fgets for at springe første linje med kolonne-navnene over
    char header[1024];
    fgets(header, sizeof header, input_file);
    // ligesom i read_child_from_file, så tjekkes der også her om overskrifterne kan læses
    if (fgets(header, sizeof header, input_file) == NULL)
    {
        fprintf(stderr, "Kunne ikke læse overskriften\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    child_t input_child = read_child_from_file(input_file);
    child_t another_child = read_child_from_file(input_file);

    fclose(input_file);

    printf("Name\tCPR-number\tSibling institution index (-1 = none)\tPreferences 1-5\n");

    print_child(input_child);
    print_child(another_child);

    return 0;
}
