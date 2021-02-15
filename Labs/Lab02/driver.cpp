#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "student_db.h"

using namespace std;

int main(int argc, char const ** argv) {
	//declare some things
	fstream f;
	int numStuds;
	string fileName = "inputs.txt";
	
	//open the file, read number of students
	f.open(fileName.c_str(), ios::in);

	//if it fails, prompt for file input
	while (f.fail()) {
		cout << "ERROR: File does not exist. Please enter a valid filename: ";
		cin >> fileName;
		f.open(fileName.c_str(), ios::in);
	}

	//fetch number of students
	f >> numStuds;
	
	//create buffer array of [numStuds] students
	student * student_arr = create_student_db(numStuds);
	
	//populate array with fstream
	populate_array(student_arr, numStuds, f);
	
	//close file stream, switch to output
	f.close();
	f.open("output.txt", ios::out);
	f << "STUDENTS SORTED BY ID" << endl;
	
	//sort by ID number, write array to file
	sort_by_id(student_arr, numStuds);
	get_student_db_info(student_arr, numStuds, f);
	
	f << "STUDENTS SORTED BY LAST NAME" << endl;
	
	//sort by last name, write array to file
	sort_by_last_name(student_arr, numStuds);
	get_student_db_info(student_arr, numStuds, f);
	
	//close stream
	f.close();
	
	//delete buffer array
	delete_student_db_info(student_arr);
	
	//return 0, end program
	return 0;
}