#include "HeaderFile.h"

FILE* filechoice() {

    ///FILE *input_file = fopen("children.tsv", "r");
    int choise;
    FILE* input_file;

    /*
    Udskriver de forskellige valgmuligheder til brugeren, samt indlæser brugerens valg
    */
    printf("Select a dataset\n");
    printf("1. For dataset nr.1\n");
    printf("2. For dataset nr.2\n");
    printf("3. For dataset nr.3\n");

    scanf("%d", &choise);

    /*
    En switch case der åbner en file baseret på brugerens valg
    */
    switch (choise) {
        case 1:
            input_file = fopen("children.tsv", "r");
            break;

        case 2:
            printf("dataset not implemented\n"); // mangler et datasæt
            return 0;
            //break;

        case 3:
            printf("dataset not implemented\n"); // mangler et datasæt
            return 0;
            //break;

        default:
            printf("invalid dataset\n");
            return 0;
    }

    if (input_file == NULL)
    {
        printf("Error: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    printf("dataset opened\n");

    return input_file;
}