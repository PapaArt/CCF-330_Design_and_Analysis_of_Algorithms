#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef FRAME_H
#define FRAME_H

char **init_frame();
//void frame(char **frame, int choice, int n);
void print_frame(char **frame);
void asterisk(char **frame, int n);
void plus_asterisk(char **frame, int n);
void X_asterisk(char **frame);
void random_art();
void jordan1(char **frame);
void jordan2(char **frame);

#endif