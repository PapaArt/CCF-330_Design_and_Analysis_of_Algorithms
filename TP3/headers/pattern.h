#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define NO_CARTESIAN 2
#define NO_CHARS 256
#define LINE 16
#define COL 2

char **initializeCartesian();
void badCharHeuristic(char *str, int size, int badChar[NO_CHARS]);
void search(char *txt, char *pat);
void cartesianProduct(char **cartesian, char arr1[], char arr2[], int n, int n1);
char *selectCartesian(char **cartesian);
void printCartesian(char **cartesian);
void printPattern(char *pattern);
int max(int a, int b);