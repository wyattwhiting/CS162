#include <iostream>
using namespace std;

void print_user_info(user* u){
   cout << "Username is: " << (*u).name << endl;
   cout << "Their ID is " << u->id << endl;
   cout << "Their password is " << "NICE TRY" << endl;
   cout << endl;
}