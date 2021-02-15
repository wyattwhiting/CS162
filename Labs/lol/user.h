#ifndef USER_H
#define USER_H

#include <iostream>

struct user{
   string name;
   int id;
   string password;
};

void print_user_info(user*);

#endif