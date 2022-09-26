#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef FRAME_H
#define FRAME_H

char **init_frame();
int check_input(int n);
int check_input_jordan(int n);
void print_frame(char **frame);
void asterisk(char **frame, int n);
void plus_asterisk(char **frame, int n);
void X_asterisk(char **frame, int n);
void random_art(char **frame, int n);
void jordan1(char **frame, int n);
void jordan2(char **frame, int n);
void jumpman_logo(char **frame, int n);

#endif