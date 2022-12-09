#include "../headers/pattern.h"

// Fazer uma matriz com os produtos cartesianos
// Gerar um valor randomico de 0 a 3
// Escolher as linhas com os padrões que serão buscados na sequência dps

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

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badChar[NO_CHARS];

    badCharHeuristic(pat, m, badChar);

    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s+j])
            j--;
        if (j < 0)
        {
            printf("Pattern occurs at shift = %d\n", s);
            s += (s+m < n) ? m - badChar[txt[s+m]] : 1;
        }
        else
            s += max(1, (j - badChar[txt[s+j]]));
    }
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
        printf("%c%c ", pattern[i], pattern[i++]);
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