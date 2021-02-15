#include <iostream>
using namespace std;


int main(){
   user u1;
   u1.name = "Dwayne Johnson";
   u1.id = 1000000;
   u1.password = "th3r0ck1sCo0k1ng";
   print_user_info(&u1);

   return 0;
}