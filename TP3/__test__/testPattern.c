#include "../headers/pattern.h"

void main(){
    char txt[] = "ACTG";
    char txt2[] = "ACTG";
    char hum[] = "AACCCTG";
    char chim[] = "AACCTG";
    char pat[] = "AA";
    char **cartesian = initializeCartesian(); 
    int n = 2 * NO_CARTESIAN;
    search(chim, pat[0], pat[1]);
    cartesianProduct(cartesian, txt, txt2, n, n);
    //printPattern(selectCartesian(cartesian));
    //printCartesian(cartesian);
}