/******************************************************
** Program: main.cpp
** Author: Wyatt Whiting
** Date: 2020-10-09
** Description: Oregon State University, CS162, Fall 2020
**              Program 1: Wizard Spellbook Catalog
** Input: two filenames for command line arguments
**        main [wizards file] [spellbook file]
** Output: allows user to log in and presents them with menu
**         to sort, display, and write to file 
**         information read in from input files
******************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "helper.h"

using namespace std;


//main function
//not well-modularized, but I don't have the patience to refactor a bunch of it
//and am willing to take the -3 point deduction, as main() is only a single function
int main(int argc, char ** argv) {
    //declare some objects and variables
    ifstream fin;

    //login and user type flags
    bool is_logged_in = false;
    bool is_student = false;

    //numbers we need to pass around or keep track of
    int numWizards;
    int numSpellbooks;
    int login_tries = 0;

    //arrays of wizards and spells for sorting/searching
    wizard * wizard_arr;
    spellbook * spellbook_arr;

    //input variables
    string usrID = "";
    string usrPassword = "";

    //check files are ok, quit otherwise. Prints error type as well
    if(!are_valid_files(argc, argv[1], argv[2], fin)) return 0;

    //make and populate spellbook buffer array
    fin.open(argv[1], ios::in);
    fin >> numWizards; 
    wizard_arr = create_wizard_arr(numWizards);
    get_wizard_data(wizard_arr, numWizards, fin);
    fin.close();

    //make and populate spellbook buffer array
    fin.open(argv[2], ios::in);
    fin >> numSpellbooks; //get number of spellbooks
    spellbook_arr = create_spellbooks(numSpellbooks);
    get_spellbook_data(spellbook_arr, numSpellbooks, fin);
    fin.close();

    //login tree
    while (!is_logged_in) {
        //prompt login and get ID/Password
        print_login();
        get_user_id(&usrID);
        get_user_password(&usrPassword);

        //check if login info matches wizard in array
        if (wizard_arr_has(usrID, usrPassword, wizard_arr, numWizards, &is_student)) {
            //if found, set login flag
            is_logged_in = true;
        }

        //if there are too many login attempts, quit
        else if(login_tries == 2) {
            cout << "Too many attempts. Exiting now..." << endl;
            return 0;
        }

        //otherwise, try again and increment attempt counter
        else {
            cout << "Invalid ID or password. Please try again." << endl;
            login_tries++;
        }
    }

    //output options
    int option = 0;
    int output_mode = 0;

    //menu loop
    while(is_logged_in) {

        //print main menu, take option
        main_menu(&option, &is_logged_in);

        //as long as user is logged in, prompt for input
        if(is_logged_in) {
            //get output mode
            get_output_mode(&output_mode);

            //output requested data
            output_data(spellbook_arr, numSpellbooks, option, output_mode, is_student);
        }
    }

    //deletion
    delete_wizard_arr(wizard_arr);
    delete_spellbook_arr(spellbook_arr, numSpellbooks);

    //return zero, exit program
    return 0;
}