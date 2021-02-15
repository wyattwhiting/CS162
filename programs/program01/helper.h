/******************************************************
** Program: helper.h
** Author: Wyatt Whiting
** Date: 2020-10-09
** Description: Header file for helper.cpp
** Input: none
** Output: none
******************************************************/
#ifndef HELPER_H
#define HELPER_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

//wizard struct
struct wizard {
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};

//spellbook struct
struct spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell *s;
};

//spell struct
struct spell {
    string name;
    float success_rate;
    string effect;
};

//misc
bool try_id_again();
void print_options();
void main_menu(int *, bool *);
void get_output_mode(int *);
void output_data(spellbook *, int, int, int, bool);

//sorting functions
void sort_by_pages(spellbook *, int);
void group_by_effect(spellbook *, int);
void sort_by_success(spellbook *, int);

//spellbook functions
spellbook * create_spellbooks(int);
void get_spellbook_data(spellbook *, int, ifstream &); 
void delete_spellbook_arr(spellbook *, int);

//spell functions
spell * create_spells(int);
void get_spell_data(spell *, int, ifstream &);
float avg_success_spells(spell *, int);

//wizard functions
wizard * create_wizard_arr(int);
void get_wizard_data(wizard *, int, ifstream &);
void delete_wizard_arr(wizard *);
bool wizard_arr_has(string, string, wizard *, int, bool *);

//more misc functions
bool are_valid_files(int, char *, char *, ifstream &);
bool is_number(string);
void print_login();
void get_user_id(string *);
void get_user_password(string *);

//printing functions
void pages_to_screen(spellbook *, int);
void rates_to_screen(spellbook *, int);
void spells_to_screen(spellbook*, int, bool);
void print_only_type(spellbook *, int, string);

//file output functions
void pages_to_file(spellbook *, int, fstream &);
void rates_to_file(spellbook *, int, fstream &);
void spells_to_file(spellbook *, int, bool, fstream &);
void write_only_type(spellbook *, int, string, fstream &);
void get_file_name(string *);
void set_write_mode(string, fstream &);
#endif