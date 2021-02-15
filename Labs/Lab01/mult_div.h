#ifndef MULT_DIV_H
#define MULT_DIV_H

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

struct mult_div_values {
	int mult;
	float div;
};

bool char_is_int(char);
bool is_valid_dimensions(char *, char *);
mult_div_values ** create_table(int, int);
void set_mult_values(mult_div_values **, int, int);
void set_div_values(mult_div_values **, int, int);
void set_all_vals(mult_div_values **, int, int);
void delete_table(mult_div_values **, int);
void print_mult_vals(mult_div_values **, int, int);
void print_div_vals(mult_div_values **, int, int);
void print_tables(mult_div_values **, int, int);
bool user_continue();
bool new_vals(char *, char *);


#endif