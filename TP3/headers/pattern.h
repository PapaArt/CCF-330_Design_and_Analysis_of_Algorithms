#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CARTESIAN 2
#define NO_CHARS 256
#define LINE 4
#define COL 12

char **initializeCartesian();
void badCharHeuristic(char *str, int size, int badChar[NO_CHARS]);
void search(char *txt, char *pat);
void cartesianProduct(char **cartesian, char arr1[], char arr2[], int n, int n1);
void printCartesian(char **cartesian);
int max(int a, int b);