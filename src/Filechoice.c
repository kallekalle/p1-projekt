#include "HeaderFile.h"

FILE* Filechoice() {

    ///FILE *input_file = fopen("children.tsv", "r");
    int choice;
    FILE* input_file;

    /*
    Udskriver de forskellige valgmuligheder til brugeren, samt indlæser brugerens valg
    */
    printf("Select a dataset:\n");
    printf("'1' for dataset no. 1\n");
    printf("'2' for dataset no. 2\n");
    printf("'3' for dataset no. 3\n");

    scanf("%d", &choice);

    /*
    En switch case der åbner en file baseret på brugerens valg
    */
    switch (choice) {
        case 1:
            input_file = fopen("children.tsv", "r");
            break;

        case 2:
            printf("Dataset not implemented\n"); // mangler et datasæt
            return 0;
            //break;

        case 3:
            printf("Dataset not implemented\n"); // mangler et datasæt
            return 0;
            //break;

        default:
            printf("Invalid dataset\n");
            return 0;
    }

    if (input_file == NULL)
    {
        printf("Error: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    printf("\nDataset opened!\n\n");

    return input_file;
}