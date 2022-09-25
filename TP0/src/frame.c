#include "../headers/frame.h"
#define LINE 20
#define COL 80

char **init_frame()
{

    char **frame = (char **)malloc(LINE * sizeof(char *));
    int i, j;
    srand(time(0));
    for (i = 0; i < LINE; i++)
    {
        frame[i] = (char *)malloc(COL * sizeof(char));
        for (j = 0; j < COL; j++)
        {
            if (i == 0 || i == (LINE - 1))
            {
                frame[i][j] = '-';
            }
            else if (j == 0 || j == (COL - 1))
            {
                frame[i][j] = '|';
            }
            else
            {
                frame[i][j] = ' ';
            }
        }
    }

    return frame;
}

// void frame(char **frame, int choice, int n)
// {

//     int random_line, random_column;

//     for (int k = 0; k < n; k++)
//     {
//         random_line = (rand() % ((LINE - 2) - 1 + 1)) + 1;
//         random_column = (rand() % ((COL - 2) - 1 + 1)) + 1;

//         for (int i = 1; i < LINE - 1; i++)
//         {
//             for (int j = 1; j < COL - 1; j++)
//             {
//                 switch (choice)
//                 {
//                 case 1:
//                     frame[random_line][random_column] = asterisk();
//                     break;
//                 case 2:
//                     plus_asterisk(frame, random_line, random_column);
//                     break;

//                 default:
//                     break;
//                 }
//             }
//         }
//     }
// }

void print_frame(char **frame)
{
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", frame[i][j]);
        }
        printf("\n");
    }
}

void asterisk(char **frame, int n)
{
    int x;
    int y;

    for (int i = 0; i < n; i++)
    {
        x = (rand() % ((LINE - 2))) + 1;
        y = (rand() % ((COL - 2))) + 1;

        frame[x][y] = '*';
    }
}

void plus_asterisk(char **frame, int n)
{

    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 2))) + 1;
            y = (rand() % ((COL - 2))) + 1;

            if (frame[x][y] == ' ' && frame[x + 1][y] == ' ' && frame[x - 1][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y - 1] == ' ')
                break;
        }

        frame[x][y] = '*';
        frame[x + 1][y] = '*';
        frame[x - 1][y] = '*';
        frame[x][y + 1] = '*';
        frame[x][y - 1] = '*';
    }
}

void X_asterisk(char **frame, int n)
{
    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 2))) + 1;
            y = (rand() % ((COL - 2))) + 1;

            if (frame[x][y] == ' ' && frame[x - 1][y - 1] == ' ' && frame[x - 1][y + 1] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y + 1] == ' ')
                break;
        }
        frame[x][y] = '*';
        frame[x - 1][y - 1] = '*';
        frame[x - 1][y + 1] = '*';
        frame[x + 1][y - 1] = '*';
        frame[x + 1][y + 1] = '*';
    }
}

void random_art()
{
    // Idea: give a number to the every art and then, choose one of them randomly
}

void piano1(char **frame, int n){

    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 4))) + 1;
            y = (rand() % ((COL - 4))) + 1;

            if (frame[x][y] == ' ' && frame[x][y - 1] == ' ' && frame[x][y - 2] == ' ' && frame[x][y - 3] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ')
                break;
            else if (frame[x - 1][y] == ' ' && frame[x - 1][y - 1] == ' ' && frame[x - 1][y - 2] == ' ' && frame[x - 1][y - 3] == ' ' && frame[x - 1][y + 1] == ' ' && frame[x - 1][y + 2] == ' ' && frame[x - 1][y + 3] == ' ')
                break;
            else if (frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y - 2] == ' ' && frame[x + 1][y - 3] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 1][y + 2] == ' ' && frame[x + 1][y + 3] == ' ')
                break;
        }
        frame[x][y] = '_';
        frame[x][y - 1] = '_';
        frame[x][y - 2] = '_';
        frame[x][y - 3] = '|';
        frame[x][y + 1] = '_';
        frame[x][y + 2] = '_';
        frame[x][y + 3] = '|';
        frame[x - 1][y] = '_';
        frame[x - 1][y - 1] = '_';
        frame[x - 1][y - 2] = '_';
        frame[x - 1][y - 3] = '_';
        frame[x - 1][y + 1] = '_';
        frame[x - 1][y + 2] = '_';
        frame[x - 1][y + 3] = '_';
        frame[x + 1][y] = '=';
        frame[x + 1][y - 1] = '=';
        frame[x + 1][y - 2] = '=';
        frame[x + 1][y - 3] = '|';
        frame[x + 1][y + 1] = '=';
        frame[x + 1][y + 2] = '=';
        frame[x + 1][y + 3] = '|';
        frame[x + 2][y] = 'w';
        frame[x + 2][y - 1] = '-';
        frame[x + 2][y - 2] = '-';
        frame[x + 2][y - 3] = '|';
        frame[x + 2][y + 1] = '-';
        frame[x + 2][y + 2] = '-';
        frame[x + 2][y + 3] = '|';
    }
}

void piano2(char **frame, int n){

    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 4))) + 1;
            y = (rand() % ((COL - 4))) + 1;

            if (frame[x][y] == ' ' && frame[x][y - 1] == ' ' && frame[x][y - 2] == ' ' && frame[x][y - 3] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ')
                break;
            else if (frame[x - 1][y] == ' ' && frame[x - 1][y - 1] == ' ' && frame[x - 1][y - 2] == ' ' && frame[x - 1][y - 3] == ' ' && frame[x - 1][y + 1] == ' ' && frame[x - 1][y + 2] == ' ' && frame[x - 1][y + 3] == ' ')
                break;
            else if (frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y - 2] == ' ' && frame[x + 1][y - 3] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 1][y + 2] == ' ' && frame[x + 1][y + 3] == ' ')
                break;
        }
        frame[x][y] = '_';
        frame[x][y - 1] = '_';
        frame[x][y - 2] = '_';
        frame[x][y - 3] = '|';
        frame[x][y + 1] = '_';
        frame[x][y + 2] = '_';
        frame[x][y + 3] = '|';
        frame[x - 1][y] = '_';
        frame[x - 1][y - 1] = '_';
        frame[x - 1][y - 2] = '_';
        frame[x - 1][y - 3] = '_';
        frame[x - 1][y + 1] = '_';
        frame[x - 1][y + 2] = '_';
        frame[x - 1][y + 3] = '_';
        frame[x + 1][y] = '=';
        frame[x + 1][y - 1] = '=';
        frame[x + 1][y - 2] = '=';
        frame[x + 1][y - 3] = '|';
        frame[x + 1][y + 1] = '=';
        frame[x + 1][y + 2] = '=';
        frame[x + 1][y + 3] = '|';
        frame[x + 2][y] = 'w';
        frame[x + 2][y - 1] = '-';
        frame[x + 2][y - 2] = '-';
        frame[x + 2][y - 3] = '|';
        frame[x + 2][y + 1] = '-';
        frame[x + 2][y + 2] = '-';
        frame[x + 2][y + 3] = '|';
    }

}

void jordan1(char **frame, int n)
{
    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 2))) + 1;
            y = (rand() % ((COL - 2))) + 1;

            if (frame[x - 2][y - 3] == ' ' && frame[x - 2][y - 2] == ' ' && frame[x - 1][y] == ' ' && frame[x - 1][y - 1] == ' ' && frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 2][y - 3] == ' ' && frame[x + 2][y + 3] == ' ')
                break;
        }
        // Jordan right-handed
        frame[x - 2][y - 3] = 'o';
        frame[x - 2][y - 2] = '\\';
        frame[x - 1][y] = 'O';
        frame[x - 1][y - 1] = '\\';
        frame[x][y] = '|';
        frame[x][y + 1] = '\\';
        frame[x][y + 2] = '_';
        frame[x + 1][y] = '-';
        frame[x + 1][y - 1] = '/';
        frame[x + 1][y + 1] = '\\';
        frame[x + 2][y - 3] = '/';
        frame[x + 2][y + 3] = '\\';
    }
}

void jordan2(char **frame, int n)
{
    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 4))) + 1;
            y = (rand() % ((COL - 4))) + 1;

            if (frame[x - 2][y + 3] == ' ' && frame[x - 2][y + 2] == ' ' && frame[x - 1][y] == ' ' && frame[x - 1][y + 1] == ' ' && frame[x][y] == ' ' && frame[x][y - 1] == ' ' && frame[x][y - 2] == ' ' && frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 2][y - 2] == ' ' && frame[x + 2][y + 2] == ' ')
                break;
        }
        // Jordan left-handed
        frame[x - 2][y + 3] = 'o';
        frame[x - 2][y + 2] = '/';
        frame[x - 1][y] = 'O';
        frame[x - 1][y + 1] = '/';
        frame[x][y] = '|';
        frame[x][y - 1] = '/';
        frame[x][y - 2] = '_';
        frame[x + 1][y] = '-';
        frame[x + 1][y - 1] = '/';
        frame[x + 1][y + 1] = '\\';
        frame[x + 2][y - 3] = '/';
        frame[x + 2][y + 3] = '\\';
    }
}