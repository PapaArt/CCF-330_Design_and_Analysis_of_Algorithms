#include "../headers/frame.h"
#define LINE 20
#define COL 80

void print_frame(int choice, int n){
    
    unsigned char frame[LINE][COL];
    int i, j;
    for (i = 0; i < LINE; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (j == 0 || j == (COL - 1))
            {
                frame[i][j] = 124;
            }
            if (i == 0 || i == (LINE - 1))
            {
                frame[i][j] = 45;
            }
            if (i != 0 && i != (LINE - 1) && j != 0 && j != (COL - 1))
            {
                frame[i][j] = 32;
            }
        }
    }
    for (i = 0; i < LINE; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%c", frame[i][j]);
        }
        printf("\n");
    }
}

void asterisk(int n){
    
    

}