#include "../headers/frame.h"
#define LINE 20
#define COL 80

void print_frame(int choice, int n){
    
    unsigned char frame[LINE][COL];
    int random_line = (rand() % ((LINE-2) - 1 + 1)) + 1;
    int random_column = (rand() % ((COL-2) - 1 + 1)) + 1;
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

void asterisk(){
    
    unsigned char asterisk = 42;
}

void plus_asterisk(){

    unsigned char plus_asterisk[3][3];
    plus_asterisk[0][0] = 32;
    plus_asterisk[0][1] = 42;
    plus_asterisk[0][2] = 32;
    plus_asterisk[1][0] = 42;
    plus_asterisk[1][1] = 42;
    plus_asterisk[1][2] = 42;
    plus_asterisk[2][0] = 32;
    plus_asterisk[2][1] = 42;
    plus_asterisk[2][2] = 32;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%c", plus_asterisk[i][j]);
    //     }
    //     printf("\n");
    // }   
}

void X_asterisk(){
    unsigned char X_asterisk[3][3];
    X_asterisk[0][0] = 42;
    X_asterisk[0][1] = 32;
    X_asterisk[0][2] = 42;
    X_asterisk[1][0] = 32;
    X_asterisk[1][1] = 42;
    X_asterisk[1][2] = 32;
    X_asterisk[2][0] = 42;
    X_asterisk[2][1] = 32;
    X_asterisk[2][2] = 42;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%c", X_asterisk[i][j]);
    //     }
    //     printf("\n");
    // }
}

void random_art(){
    // Idea: give a number to the every art and then, choose one of them randomly
}

void jordan1(){
    // Jordan right-handed
    unsigned char jumpman_logo[5][7];
    jumpman_logo[0][0] = 111;
    jumpman_logo[0][1] = 92;
    jumpman_logo[0][2] = 32;
    jumpman_logo[0][3] = 32;
    jumpman_logo[0][4] = 32;
    jumpman_logo[0][5] = 32;
    jumpman_logo[0][6] = 32;
    jumpman_logo[1][0] = 32;
    jumpman_logo[1][1] = 32;
    jumpman_logo[1][2] = 92;
    jumpman_logo[1][3] = 79;
    jumpman_logo[1][4] = 32;
    jumpman_logo[1][5] = 32;
    jumpman_logo[1][6] = 32;
    jumpman_logo[2][0] = 32;
    jumpman_logo[2][1] = 32;
    jumpman_logo[2][2] = 32;
    jumpman_logo[2][3] = 124;
    jumpman_logo[2][4] = 92;
    jumpman_logo[2][5] = 95;
    jumpman_logo[2][6] = 32;
    jumpman_logo[3][0] = 32;
    jumpman_logo[3][1] = 32;
    jumpman_logo[3][2] = 47;
    jumpman_logo[3][3] = 45;
    jumpman_logo[3][4] = 92;
    jumpman_logo[3][5] = 32;
    jumpman_logo[3][6] = 32;
    jumpman_logo[4][0] = 47;
    jumpman_logo[4][1] = 32;
    jumpman_logo[4][2] = 32;
    jumpman_logo[4][3] = 32;
    jumpman_logo[4][4] = 32;
    jumpman_logo[4][5] = 32;
    jumpman_logo[4][6] = 92;

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 7; j++)
    //     {
    //         printf("%c", jumpman_logo[i][j]);
    //     }
    //     printf("\n");
    // }
}

void jordan2(){
    unsigned char jumpman_logo[5][7];
    jumpman_logo[0][0] = 32;
    jumpman_logo[0][1] = 32;
    jumpman_logo[0][2] = 32;
    jumpman_logo[0][3] = 32;
    jumpman_logo[0][4] = 32;
    jumpman_logo[0][5] = 47;
    jumpman_logo[0][6] = 111;
    jumpman_logo[1][0] = 32;
    jumpman_logo[1][1] = 32;
    jumpman_logo[1][2] = 32;
    jumpman_logo[1][3] = 79;
    jumpman_logo[1][4] = 47;
    jumpman_logo[1][5] = 32;
    jumpman_logo[1][6] = 32;
    jumpman_logo[2][0] = 32;
    jumpman_logo[2][1] = 95;
    jumpman_logo[2][2] = 47;
    jumpman_logo[2][3] = 124;
    jumpman_logo[2][4] = 32;
    jumpman_logo[2][5] = 32;
    jumpman_logo[2][6] = 32;
    jumpman_logo[3][0] = 32;
    jumpman_logo[3][1] = 32;
    jumpman_logo[3][2] = 47;
    jumpman_logo[3][3] = 45;
    jumpman_logo[3][4] = 92;
    jumpman_logo[3][5] = 32;
    jumpman_logo[3][6] = 32;
    jumpman_logo[4][0] = 47;
    jumpman_logo[4][1] = 32;
    jumpman_logo[4][2] = 32;
    jumpman_logo[4][3] = 32;
    jumpman_logo[4][4] = 32;
    jumpman_logo[4][5] = 32;
    jumpman_logo[4][6] = 92;

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 7; j++)
    //     {
    //         printf("%c", jumpman_logo[i][j]);
    //     }
    //     printf("\n");
    // }
}