#include "../headers/pattern.h"

void main(){
    char txt[] = "ACTG";
    char pat[] = "ACTG";
    char **cartesian = initializeCartesian(); 
    int n = 2 * CARTESIAN;
    //search(txt, pat);
    cartesianProduct(cartesian, txt, pat, n, n);
    printCartesian(cartesian);
}