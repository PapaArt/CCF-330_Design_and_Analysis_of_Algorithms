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
    int n = strlen(txt);
    int m = 2;
    char pat[2];
    pat[0] = pat1;
    pat[1] = pat2;
    //printf("%c%c\n", pat[0], pat[1]);
    //printf("%d\n", m);
    int badChar[NO_CHARS];

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
            //printf("Pattern occurs at shift = %d\n", s);
            s += (s+m < n) ? m - badChar[txt[s+m]] : 1;
            count++;
        }
        else
            s += max(1, (j - badChar[txt[s+j]]));
    }

    return count;
}

void cartesianProduct(char **cartesian, char arr1[], char arr2[], int n, int n1)
{
    int aux1, aux2;
    aux1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n1; j++)
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
    int position[4];
    for (int i = 0; i < 4; i++)
    {
        position[i] = (rand() % 15) + 1;
    }
    
    int i = 0;
    int aux = 0;
    while (i < 4)
    {
        pattern[aux] = cartesian[position[i]][0];
        aux++;
        pattern[aux] = cartesian[position[i]][1];
        aux++;
        i++;
    }

    return pattern;
}

void printPattern(char *pattern)
{
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

int max(int a, int b){
    return (a > b) ? a : b;
}