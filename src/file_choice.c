#include "main_header.h"

FILE *file_choice()
{
    int choice;
    FILE *input_file;

    // Prints the different options, and reads the user's input
    printf("Select a dataset:\n");
    printf("'1' for dataset no. 1\n");
    printf("'2' for dataset no. 2\n");
    printf("'3' for dataset no. 3\n");

    scanf("%d", &choice);

    // Switch-case that opens a specific file based on user input
    switch (choice)
    {
    case 1:
        input_file = fopen("children.tsv", "r");
        break;

    case 2:
        printf("Dataset not implemented\n"); // missing dataset
        return 0;
        // break;

    case 3:
        printf("Dataset not implemented\n"); // missing dataset
        return 0;
        // break;

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