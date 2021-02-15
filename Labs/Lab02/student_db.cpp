#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "student_db.h"

using namespace std;

student* create_student_db(int n) {
	//n-tuple of student structs
	student * array = new student[n];
	return array;
}

void delete_student_db_info(student * table) {
	delete[] table;
}

void sort_by_id(student * table, int n) {
	//sorting flag
	bool isSorted = false;

	//swap object
	student temp;

	//loop until sorted
	while(!isSorted) {
		isSorted = true;
		//all elements
		for(int i = 0; i < (n - 1); i++) {
			if(table[i].idNum > table[i + 1].idNum) {
				isSorted = false;
				temp = table[i];
				table[i] = table[i + 1];
				table[i + 1] = temp;
			}
		}
	}
}

void sort_by_last_name(student * a, int n) {
	bool isSorted = false;
	student temp;
	while(!isSorted) {
		isSorted = true;
		for(int i = 0; i < (n - 1); i++) {
			if(a[i].lastName.compare(a[i+1].lastName) > 0) {
				isSorted = false;
				temp = a[i];
				a[i] = a[i+1];
				a[i + 1] = temp;
			}
		}
	}
}

//for debugging
void print_table(student * a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "Student: " << i << endl;
		cout << a[i].idNum << endl;
		cout << a[i].firstName << endl;
		cout << a[i].lastName << endl;
		cout << a[i].major << endl;
	}
	cout << endl;
}

void get_student_db_info(student * a, int n, fstream & f) {
	//for each student in array
	for(int i = 0; i < n; i++) {
		//print info to the line
		f << a[i].idNum << " ";
		f << a[i].firstName << " ";
		f << a[i].lastName << " ";
		f << a[i].major << endl;
	}
	//extra line for formatting
	f << endl;
}

void populate_array(student * a, int n, fstream & f) {
	for(int i = 0; i < n; i++) {
		f >> a[i].idNum;
		f >> a[i].firstName;
		f >> a[i].lastName;
		f >> a[i].major;
	}
}

