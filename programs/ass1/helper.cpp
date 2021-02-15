/******************************************************
** Program: helper.cpp
** Author: Wyatt Whiting
** Date: 2020-10-09
** Description: .cpp file for function deifinons from helper.h.
**              most of the program logic goes on inside here
** Input: none
** Output: none
******************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "helper.h"

using namespace std;

//function to allote memory for spellbook array
//returns spellbook pointer for n-tuple array
spellbook * create_spellbooks(int n) {
    //create n-tuple of spellbook structs and return 
    spellbook * array = new spellbook[n];
    return array;
}

//function to populate spellbook array with values from file
//the ifstream object must already have the proper file open
//and progressed beyond the spellbook count at the top of the file
void get_spellbook_data(spellbook * a, int n, ifstream & f) {
    //loop for spellbooks
    for(int i = 0; i < n; i++) {
        //input the easy stuff
        f >> a[i].title;
        f >> a[i].author;
        f >> a[i].num_pages;
        f >> a[i].edition;
        f >> a[i].num_spells;
        
        //make spell array with appropriate number of spells
        a[i].s = create_spells(a[i].num_spells);
        get_spell_data(a[i].s, a[i].num_spells, f); //populate temp spell array

        //calculate and input average success rate
        a[i].avg_success_rate = avg_success_spells(a[i].s, a[i].num_spells);
    }
}

//function to de-allocate memory for spellbook array
//also de-allocates memory for spell array inside struct
//called at the end of the program
void delete_spellbook_arr(spellbook * a, int n) {
    //loop through spellbooks, delete spell array
    for(int i = 0; i < n; i++) delete[] a[i].s;
    //delete spellbook array
    delete[] a;
}

//function to allocate memory for spell array
//return pointer to n-tuple of spells
spell * create_spells(int n) {
    //create n-tuple of spells
    spell * array = new spell[n];
    return array;
}

//function to populate spell array with information from file
//ifstream cursor must be advanced to line with spell information
void get_spell_data(spell * a, int n, ifstream & f) {
    //loop through indicated number of spells
    for(int i = 0; i < n; i++) {
        //populate fields
        f >> a[i].name;
        f >> a[i].success_rate;
        f >> a[i].effect;
    }
}

//function to find the average success rate of a spell array
//spell array must be populated with information from file
float avg_success_spells(spell * a, int n) {
    //track the sum
    float sum = 0.0;

    //add up the success rates
    for(int i = 0; i < n; i++) {
        sum += a[i].success_rate;
    }

    //return the average
    return ((float)sum / (float)n);
}

//function to validate that given filenames are available in directory
//n must be the number of arguments passed in main
//ifstream need not be initialized and is reset after function terminates
//this will also indicate the type of error
//returns whether files are valid or not
bool are_valid_files(int n, char * arg1, char * arg2, ifstream & f) {
    //if too few arguments, print error, close input stream, return false
    if (n < 3) {
        cout << "ERROR: exactly two files were not specified. Exiting now..." << endl;
        f.close();
        return false;
    }

    //check if wizards file exists, print error and return false if not
    f.open(arg1, ios::in);
    if(f.fail()) {
        cout << "ERROR: specified wizards file does not exist. Exiting now..." << endl;
        f.close();
        return false;
    }

    //reset input stream 
    f.close();

    //check if spellbooks file exists, print error and return false if not
    f.open(arg2, ios::in);
    if(f.fail()) {
        cout << "ERROR: specified spellbooks file does not exist. Exiting now..." << endl;
        f.close();
        return false;
    }

    //reset input stream
    f.close();

    //if made it here, both files exists
    return true;
}

//function to print an error message relating to ID characters
//returns true to work with some hacky logic 
//trust me, it's clever and very cool :^)
bool try_id_again() {
    //print error message
    cout << "ID has non-digital characters. Please try again." << endl;
    return true;
}

//function to print login header to screen 
//that's it
void print_login() {
    //print login header
    cout << "___...---===LOGIN===---...___" << endl;
}

//function to print menu options to screen
//that's it
void print_options() {
    //print main menu options
    cout << "Please select an option: " << endl;
    cout << "1 - Sort spellbooks by number of pages" << endl;
    cout << "2 - Group spells by effect" << endl;
    cout << "3 - Sort spellbooks by average success rate" << endl;
    cout << "4 or else - Exit program" << endl;
}

//function to sort a spellbook array by number of pages, ascending
//spellbook array must be populated with data from file
//otherwise, bad things will happen
void sort_by_pages(spellbook * a, int n) {
    //sorted flag
    bool is_sorted = false;

    //make temp spellbook for swap
    spellbook temp;

    //as long as it isn't sorted
    while(!is_sorted) {
        //assume it is sorted
        is_sorted = true;

        //loop through each pair of spellbooks
        for(int i = 0; i < (n - 1); i++) {
            //when unordered pair is found, swap
            if(a[i].num_pages > a[i + 1].num_pages) {
                //flip flag
                is_sorted = false;

                //swap
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

//function to sort a spellbook array by average success rate, ascending
//spellbook array must be populated with information from file before calling
void sort_by_success(spellbook * a, int n) {
    //sorted flag
    bool is_sorted = false;

    //make temp spellbook for swap
    spellbook temp;

    //loop through each pair of spellbooks
    while(!is_sorted) {
        //assume it's sorted
        is_sorted = true;

        //loop through each pair of spellbooks
        for(int i = 0; i < (n - 1); i++) {
            //when unordered pair is found
            if(a[i].avg_success_rate > a[i + 1].avg_success_rate) {
                //flip flag
                is_sorted = false;

                //swap
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

//function to present main menu and determine if user wants to remain logged in
//option need not be initialized, as this function will write over any value it holds
//logged_in will be true when called, this can only set it to false if necessary
void main_menu(int * option, bool * logged_in) {
    //print main menu options, take input
    print_options();
    cin >> *option;

    //if not in [1,3], change login flag to false
    if (*option != 3 && *option != 2 && *option != 1) *logged_in = false;
}

//function to get desired output mode from user
//input must be either 0 or 1 for later logic to work
void get_output_mode(int * n) {
    //print output options
    cout << "How would you like your information displayed? " << endl;
    cout << "0 - Print to screen" << endl;
    cout << "1 - Print to file" << endl;

    //take option
    cin >> *n;
}

//function to translate user choices on sorting and output into real output
//is_student is passed to other functions for determining which spell types to show
//essentially a big tree that calls the print/write functions as necessary
void output_data(spellbook * a, int num, int op, int outmode, bool is_student) {
    //print to screen
    if(outmode == 0) {
        //sort by pages
        if(op == 1) pages_to_screen(a, num);
        //sort by success rate
        if(op == 3) rates_to_screen(a, num);
        //group by spell type
        if(op == 2) spells_to_screen(a, num, is_student);
    }

    //otherwise, write to file
    else {
        //make new fstream object and filename variable
        fstream f;
        string outfile;

        //get the filename
        get_file_name(&outfile);

        //using filename, determine whether we use ios::out or with ios::app
        set_write_mode(outfile, f);

        //use user option to write appropriate data
        if(op == 1) pages_to_file(a, num, f);
        if(op == 3) rates_to_file(a, num, f);
        if(op == 2) spells_to_file(a, num, is_student, f);

        //close the file stream
        f.close();

    }
}

//function to determind if fstream will be writing a new file or appending to existing.
//it only sets the mode that fstream is operating in 
//fstream need not be initilized upon calling,
//but must be closed afterwards.
void set_write_mode(string s, fstream & f) {
    //try to open filename
    f.open(s.c_str(), ios::in);

    //if file doesn't exist
    if(f.fail()) {
        //close failed filestream
        f.close();

        //reopen, set to output mode with given filename
        f.open(s.c_str(), ios::out);
    }

    //otherwise, it already does
    else {
        //close filestream
        f.close();

        //set to append mode 
        f.open(s.c_str(), ios::out|ios::app);
    }
}

//function to print prompt for a filename
//stores input in *s
void get_file_name(string * s) {
    //prompt file input
    cout << "Please enter a file name: ";
    cin >> *s;
}

//function to print book title and page number to screen,
//sorted by ascending page number
//spellbook array must have data from file 
void pages_to_screen(spellbook * a, int num)  {
    //sort array by number of pages
    sort_by_pages(a, num);
    cout << endl;

    //loop through spellbooks
    for(int i = 0; i < num; i++) {
        //print each line in turn
        cout << a[i].title << " " << a[i].num_pages << endl;
    }

    //formatting
    cout << endl;
}

//function to print book title and average success rate of spells within that book to screen,
//sorted by ascending average success rate
//spellbook array must have data from file
void rates_to_screen(spellbook * a, int num) {

    //sort array by average spell success rate
    sort_by_success(a, num);
    cout << endl;

    //loop through all spellbooks
    for(int i = 0; i < num; i++) {
        //print out each line in turn
        cout << a[i].title << " " << a[i].avg_success_rate << endl;
    }

    //formatting
    cout << endl;
}

//function to print list of spells, grouped by type
//relies on is_student flag to determine if poison and death should be shown.
//as such, is_student must have the proper value determined earlier in program,
//and the spellbook array must be populated with data
void spells_to_screen(spellbook * a, int num, bool is_student) {
    //print each type of spell in turn
    print_only_type(a, num, "bubble");
    print_only_type(a, num, "memory_loss");
    print_only_type(a, num, "fire");

    //only print poison and death if not a student
    if(!is_student) {
        print_only_type(a, num, "poison");
        print_only_type(a, num, "death");
    }
    cout << endl;
}

//function to print only spells of type "s" to screen
//"s" must be the desired spell type
//will ignore all others
//spellbook array must have data from file
void print_only_type(spellbook * a, int num, string s) {

    //loop through all spellbooks
    for(int i = 0; i < num; i++) {

        //loop through all spells in array
        for(int j = 0; j < a[i].num_spells; j++) {

            //if the type matches, print to screen
            if (!a[i].s[j].effect.compare(s)){
                cout << a[i].s[j].effect << " " << a[i].s[j].name << endl;
            }
        }
    }
}

//function to write spellbook title and number of pages to file,
//in ascending order
//fstream object must already be set to write to desired file before calling
//spellbook array must be populated with data from file
void pages_to_file(spellbook * a, int num, fstream & f) {
    //sort array by number of pages
    sort_by_pages(a, num);
    cout << endl;

    //loop through spellbooks, write out info
    for(int i = 0; i < num; i++) {
        f << a[i].title << " " << a[i].num_pages << endl;
    }

    //formatting
    cout << endl;
}

//function to write spellbook title and average success rate to file,
//in ascending order
//fstream object must already be set to write to desired file before calling
//spellbook array must be popualted with data from file
void rates_to_file(spellbook * a, int num, fstream & f) {
    //sort array by average spell success rate
    sort_by_success(a, num);
    cout << endl;

    //loop through all spellbooks, write info to file
    for(int i = 0; i < num; i++) {
        f << a[i].title << " " << a[i].avg_success_rate << endl;
    }

    //formatting
    cout << endl;
}

//write spells to file, grouped by type and permissioned based on is_student
//is_student must have proper flag set earlier in program
//spellbook must be populated with data from file
//fstream object must be set to write to appropriate file before calling
void spells_to_file(spellbook * a, int num, bool is_student, fstream & f) {
    //write each type of spell in turn
    write_only_type(a, num, "bubble", f);
    write_only_type(a, num, "memory_loss", f);
    write_only_type(a, num, "fire", f);

    //only write poison and death if not a student
    if(!is_student) {
        write_only_type(a, num, "poison", f);
        write_only_type(a, num, "death", f);
    }

    //formatting
    cout << endl;
}

//function to write spells of type "s" to file
//fstream must be set to write to file before calling
//spellbook must be popualted with data from file
//"s" indicates the spell type to print to file,
//all else being ignored
void write_only_type(spellbook * a, int num, string s, fstream & f) {
    //loop through all spellbooks
    for(int i = 0; i < num; i++) {

        //loop through all spells in array
        for(int j = 0; j < a[i].num_spells; j++) {

            //if the type matches, print to screen
            if (!a[i].s[j].effect.compare(s)){
                f << a[i].s[j].effect << " " << a[i].s[j].name << endl;
            }
        }
    }
}

//function to determine if string consists only of numbers
//returns whether "s" consists of only digits
bool is_number(string s) {
    //loop through all characters in string
    for(int i = 0; i < s.length(); i++) {
        //if non-digit is found, return false
        if(!isdigit(s[i])) return false;
    }

    //otherwise, return true
    return true;
}  

//function to prompt and take input for id
//stores input in *s
//will loop and print error as long as non-numerical input is entered
void get_user_id(string * s) {
    //print prompt and take in input
    do {
        cout << "ID:";
        cin >> *s;
    } 

    //check if given input is a number, print tryagain prompt if so
    //also, I like this use of short-circuiting
    while(!is_number(*s) && try_id_again());
    
}

//function to prompt and take in password
//stores result in *s
void get_user_password(string * s) {
    //prompt for password and store input
    cout << "Password:";
    cin >> *s;
}

//function to allocate memory for an array of wizards
//return pointer to n-tuple of wizards
wizard * create_wizard_arr(int n) {
    //n-tuple of wizard structs
    wizard * array = new wizard[n];
    return array;
}

//function to populate wizard array with data from file
//ifstream must have cursor past the initial wizard count in file
void get_wizard_data(wizard * a, int n, ifstream & f) {
    //loop through all wizards in array
    for(int i = 0; i < n; i++) {
        //read in data according to template
        f >> a[i].name;
        f >> a[i].id;
        f >> a[i].password;
        f >> a[i].position_title;
        f >> a[i].beard_length;
    }
}

//de-allocates memory for array of wizards
//that's it. simple.
void delete_wizard_arr(wizard * a) {
    //delete wizard array
    delete[] a;
}

//function to determine if a wizard array contains an entry matching a given id and password
//returns if usr and pass is within the wizard array
//wizard array must be populated with data from file
//also sets *is_student flag if user is a student,
//and prints basic info after match is found for login
bool wizard_arr_has(string usr, string pass, wizard * a, int n, bool * is_student) {
    //loop through all wizards
    for(int i = 0; i < n; i++) {
        //if a password and username match is found...
        if(a[i].password.compare(pass) == 0 && stoi(usr) == a[i].id) {
            //check if user is a student, switch flag if necessary
            if(!a[i].position_title.compare("Student")) *is_student = true;

            //print user information
            cout << endl;
            cout << "Welcome, " << a[i].name << "!" << endl;
            cout << "ID: " << a[i].id << endl;
            cout << "Position: " << a[i].position_title << endl;
            cout << "Beard length: " << a[i].beard_length << endl;
            cout << endl;


            //exit the function
            return true;
        }
    }
    //otherwise, none were found and login fails
    return false;
}