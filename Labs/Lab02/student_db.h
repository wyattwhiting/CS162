#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

struct student {
	int idNum;
	string firstName;
	string lastName;
	string major;
};

student* create_student_db(int); 
void get_student_db_info(student *, int, fstream &); 
void delete_student_db_info(student *); 
void sort_by_id(student *, int);
void sort_by_last_name(student *, int);
void populate_array(student *, int, fstream &);
void print_table(student *, int);

#endif