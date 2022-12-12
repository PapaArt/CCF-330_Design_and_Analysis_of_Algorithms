#include "../headers/pattern.h"

char **initializeCartesian()
{
    srand(time(0));
    char **cartesian = (char**)malloc(LINE * sizeof(char *));
    for (int i = 0; i < LINE; i++){
        cartesian[i] = (char *)malloc(COL * sizeof(char));
        for (int j = 0; j < COL; j++){
            cartesian[i][j] = ' ';
        }
    }

    return cartesian;      
}

void badCharHeuristic(char *str, int size, int badChar[NO_CHARS])
{
    int i;
    for (i = 0; i < NO_CHARS; i++)
    {
        badChar[i] = -1;
    }
    for (i = 0; i < size; i++)
    {
        badChar[str[i]] = i;
    }
}

int search(char *txt, char pat1, char pat2)
{
    int badChar[NO_CHARS];
    int n = strlen(txt);
    int m = 2;
    char pat[2];

    pat[0] = pat1;
    pat[1] = pat2;

    badCharHeuristic(pat, m, badChar);

    int s = 0;
    int count = 0;

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s+j])
            j--;
        if (j < 0)
        {
            s += (s+m < n) ? m - badChar[txt[s+m]] : 1;
            count++;
        }
        else
            s += max(1, (j - badChar[txt[s+j]]));
    }

    return count;
}

void cartesianProduct(char **cartesian, char arr1[], char arr2[], int n)
{
    int aux1, aux2;
    aux1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux2 = 0;
            cartesian[aux1][aux2] = arr1[i];
            aux2++;
            cartesian[aux1][aux2] = arr2[j];
            aux1++;
        }
    }
}

char *selectCartesian(char **cartesian)
{
    char *pattern = (char *)malloc((LINE/2) * sizeof(char));
    int position[NO_CARTESIAN];
    for (int i = 0; i < NO_CARTESIAN; i++)
    {
        position[i] = (rand() % 15) + 1;
    }
    
    // Verify if the array has any duplicates
    for (int i = 0; i < NO_CARTESIAN; i++) {
        for (int j = i + 1; j < NO_CARTESIAN; j++) {
        if (position[i] == position[j]) {
                position[i] = (rand() % 15) + 1;
            }
        }
    }

    int i = 0;
    int aux = 0;
    while (i < NO_CARTESIAN)
    {
        pattern[aux] = cartesian[position[i]][0];
        aux++;
        pattern[aux] = cartesian[position[i]][1];
        aux++;
        i++;
    }

    return pattern;
}

double similarity(int A[], int B[])
{
    double sum = 0.0;
    double normX = 0.0; 
    double normY = 0.0;
    double similarity = 0.0;
    size_t n = sizeof(&A) / 2;
    for (int i = 0; i < n; i++)
    {
        sum += (A[i] * B[i]);
        normX += pow(A[i], 2);
        normY += pow(B[i], 2);
    }
    normX = sqrt(normX);
    normY = sqrt(normY);

    similarity = (sum / (normX * normY));
    
    return similarity;
}

void printPattern(char *pattern)
{
    printf("Padrão de sequência a ser buscado: ");
    for (int i = 0; i < (LINE/2); i++)
    {
        printf("%c", pattern[i]);
    }
    printf("\n");
}

void printCartesian(char **cartesian)
{
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", cartesian[i][j]);
        }printf("\n");
    }
}

void printArrayAB(int A[], int B[])
{
    for (int i = 0; i < NO_CARTESIAN; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < NO_CARTESIAN; i++)
    {
        printf("%d ", B[i]);
    }printf("\n");
}

int max(int a, int b){
    return (a > b) ? a : b;
}