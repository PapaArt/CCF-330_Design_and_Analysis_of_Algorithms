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

void random_art(char **frame, int n)
{
    // Idea: give a number to the every art and then, choose one of them randomly
    printf("Nada ainda otário\n");
}

void jordan1(char **frame, int n)
{
    // Jordan right-handed
    int x, y;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = (rand() % ((LINE - 2))) + 2;
            y = (rand() % ((COL - 2))) + 2;

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
            x = (rand() % ((LINE - 2))) + 2;
            y = (rand() % ((COL - 2))) + 2;

            if (frame[x - 2][y + 3] == ' ' && frame[x - 2][y + 2] == ' ' && frame[x - 1][y] == ' ' && frame[x - 1][y + 1] == ' ' && frame[x][y] == ' ' && frame[x][y - 1] == ' ' && frame[x][y - 2] == ' ' && frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 2][y - 3] == ' ' && frame[x + 2][y + 3] == ' ')
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

void jumpman_logo(char **frame, int n)
{

    int x, y, jordan;

    for (int i = 0; i < n; i++)
    {
        jordan = (rand() % (2));
        while (1)
        {
            x = (rand() % ((LINE - 2))) + 2;
            y = (rand() % ((COL - 2))) + 2;

            // Jordan = 0 -> Left-handed
            // Jordan = 1 -> Right-handed
            if (jordan == 0)
            {
                if (frame[x - 2][y + 3] == ' ' && frame[x - 2][y + 2] == ' ' && frame[x - 1][y] == ' ' && frame[x - 1][y + 1] == ' ' && frame[x][y] == ' ' && frame[x][y - 1] == ' ' && frame[x][y - 2] == ' ' && frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 2][y - 3] == ' ' && frame[x + 2][y + 3] == ' ')
                    break;
            }
            else
            {
                if (frame[x - 2][y - 3] == ' ' && frame[x - 2][y - 2] == ' ' && frame[x - 1][y] == ' ' && frame[x - 1][y - 1] == ' ' && frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x + 1][y] == ' ' && frame[x + 1][y - 1] == ' ' && frame[x + 1][y + 1] == ' ' && frame[x + 2][y - 3] == ' ' && frame[x + 2][y + 3] == ' ')
                    break;
            }
        }
        if (jordan == 0)
        {
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
        else
        {
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
}