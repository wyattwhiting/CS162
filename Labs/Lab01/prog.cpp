#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "mult_div.h"
using namespace std;

int main(int argc, char const ** argv) {
	//make copy of arguments
	char * arg1 = (char*)argv[1];
	char * arg2 = (char*)argv[2];
	
	do {
		//run dimension check and correction
		is_valid_dimensions(arg1, arg2);
		
		//create mult_div table
		mult_div_values ** table = create_table(atoi(arg1), atoi(arg2));
		
		//popualate structs with values
		set_all_vals(table, atoi(arg1), atoi(arg2));
		
		//print tables
		print_tables(table, atoi(arg1), atoi(arg2));
		
		//delete table from heap
		delete_table(table, atoi(arg1));
			
	} while(user_continue() && new_vals(arg1, arg2));
	 
	//return 0 and end program
	return 0;
}