#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "mult_div.h"
using namespace std;

bool char_is_int(char m) {
	return (m >= 49 && m <= 57 );
}

//check if both are in range simultaneously
bool is_valid_dimensions(char * m, char * n) {
	//check chars are in range of ascii integers
	while (!(char_is_int(*m) && char_is_int(*n))) {
		cout << "Arguments must be a non-zero integer." << endl;
		cout << "Please enter a valid ";
		//check first
		if (!char_is_int(*m)) {
			cout << "row: ";
			cin >> *m;
		}
		//if not, must be second
		else {
			cout << "column: ";
			cin >> *n;
		}
	}
}

mult_div_values** create_table(int m, int n) {
	mult_div_values ** table = new mult_div_values*[m];
	for(int i = 0; i < m; i++) {
		table[i]  = new mult_div_values[n];
	}
	return table;
}

void set_mult_values(mult_div_values **table, int m, int n) {
	//loop through rows
	for (int i = 0; i < m; i++) {
		//through all columns
		for (int j = 0; j < n; j++) {
			//set mul and div values for each object
			table[i][j].mult = (i + 1) * (j + 1);
		}
	}
}
void set_div_values(mult_div_values **table, int m, int n) {
	//loop through rows
	for (int i = 0; i < m; i++) {
		//through all columns
		for (int j = 0; j < n; j++) {
			//set mul and div values for each object
			table[i][j].div = ((float)(i + 1) / (float)(j + 1));
		}
	}
}

void set_all_vals(mult_div_values ** table, int m, int n) {
	set_mult_values(table, m, n);
	set_div_values(table, m, n);
}

void delete_table(mult_div_values **table, int m) {
	//loop through rows
	for (int i = 0; i < m; i++) {
		delete[] table[i];
	}
	delete[] table;
}

void print_mult_vals(mult_div_values ** table, int m, int n) {
	//print table type
	cout << "Multiplication Table:" << endl;
	//loop through rows
	for(int i = 0; i < m; i++) {
		//loop through columns
		for(int j = 0; j < n; j++) {
			cout << table[i][j].mult;
			if(table[i][j].mult < 10) cout << "  ";
			else cout << " ";
		}
		cout << endl;
	}
}

void print_div_vals(mult_div_values ** table, int m, int n) {
	//print table type
	cout << "Division Table:" << endl;
	//loop through rows
	for(int i = 0; i < m; i++) {
		//loop through columns
		for(int j = 0; j < n; j++) {
			cout << setprecision(2) << fixed << table[i][j].div;
			if(table[i][j].div < 10.0) cout << "  ";
			else cout << " ";
		}
		cout << endl;
	}
}

void print_tables(mult_div_values ** table, int m, int n) {
	print_mult_vals(table, m, n);
	print_div_vals(table, m, n);
}

bool user_continue() {
	cout << "Would you like to see a different size matrix? (0-no, 1-anything else)" << endl;
	char usrInput;
	cin >> usrInput;
	return usrInput != '0';
}

bool new_vals(char * m, char * n) {
	cout << "Number of rows: ";
	cin >> *m;
	cout << "Number of columns: ";
	cin >> *n;
	return true;
}