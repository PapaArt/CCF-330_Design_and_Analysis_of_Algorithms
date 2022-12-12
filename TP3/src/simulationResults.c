#include "../headers/simulationResults.h"

#include <unistd.h>

void simulation() {
    int A[NO_CARTESIAN], B[NO_CARTESIAN];
    int aux1, aux2;
    double similarityValues[1000];
    double similarityAverage = 0.0;
    int i;
    int n = 4;
    char txt[] = "ACTG";
    char txt2[] = "ACTG";
    char buffer[1000];
    char path[100], path2[100];
    const char *basePath = "./data/";
    int randomSequence = (rand() % (220000 - 4 + 1)) + 4;
    char **cartesian = initializeCartesian();
    char *firstSequence;
    char *secSequence;
    char *pattern;
    FILE *fptr;
    FILE *fptr2;
    FILE *test;
    char filename[100], filename2[100];

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", filename);
    strcat(strcpy(path, basePath), filename);
    printf("%s\n", path);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", filename2);
    strcat(strcpy(path2, basePath), filename2);
    printf("%s\n", path2);

    fptr = fopen(path, "r");
    fptr2 = fopen(path2, "r");

    while (!(fptr)) {
        printf("Erro ao ler arquivo!\n");
        printf("Insira o nome do primeiro arquivo novamente: ");

        scanf("%s", filename);

        strcat(strcpy(path, basePath), filename);

        (fptr) = fopen(path, "r");
    }

    while (!(fptr2)) {
        printf("Erro ao ler arquivo!\n");
        printf("Insira o nome do segundo arquivo novamente: ");

        scanf("%s", filename2);

        strcat(strcpy(path2, basePath), filename2);

        (fptr2) = fopen(path2, "r");
    }

    char name[150] = "./files/";
    strcat(strcat(name, strcat(filename, filename2)), ".csv");

    srand(time(0));

    firstSequence = (char *)malloc(220000 * sizeof(char));
    secSequence = (char *)malloc(220000 * sizeof(char));

    for (int max = 1; max < 21; max++) {
        similarityAverage = 0.0;
        cartesianProduct(cartesian, txt, txt2, n);

        int j = 0;

        while (j < max) {
            pattern = selectCartesian(cartesian);
            randomSequence = (rand() % (220000 - 4 + 1)) + 4;
            aux1 = 0;
            aux2 = 1;
            for (int i = 0; i < randomSequence; i++) {
                fscanf(fptr, "%c", &firstSequence[i]);
                fscanf(fptr2, "%c", &secSequence[i]);
            }

            for (i = 0; i < NO_CARTESIAN; i++) {
                A[i] = search(firstSequence, pattern[aux1], pattern[aux2]);
                B[i] = search(secSequence, pattern[aux1], pattern[aux2]);
                aux1 += 2;
                aux2 += 2;
            }
            // printPattern(pattern);
            similarityValues[j] = similarity(A, B);
            similarityAverage += similarityValues[j];
            j++;
        }

        printf("Média da similaridade após %d execuções: %lf\n", max, (similarityAverage / max));

        if (access(name, F_OK) != -1) {
            test = fopen(name, "a");
            fprintf(test, "\n%d,%.5lf", max, (similarityAverage / max));
        } else {
            test = fopen(name, "w");
            fprintf(test, "N,Similarity");
            fprintf(test, "\n%d,%.5lf", max, (similarityAverage / max));
        }
        fclose(test);
    }

    fclose(fptr);
    fclose(fptr2);
}