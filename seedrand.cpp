#include <iostream>
#include <cstdlib>
using namespace std;

int getRandomNumberOne(int a){
srand(1);
a = rand () % 15;
return a;
}
int getRandomNumberSecond(int a){
srand(11);
a = rand () % 15;
return a;
}
int getRandomNumberThird(int a){
srand(11);
a = rand () % 15;
return a;
}

int main(){
int a,b,c;


a = getRandomNumberOne(0);
cout << a << endl;

b = getRandomNumberSecond(0);
cout << b << endl;

c = getRandomNumberThird(0);
cout << c << endl;

return 0;
}
/*
Alot is going on here, so I will try to explain everything. my first function is named getRandomNumberOne, and
inside of the () is an argument that has to be there, but at this point, services no use. For some reason, there
has to be something there. When it goes up to the function at the top, the srand is assigned to 1. the "% 15" means that
I want the random number picks to for 0 to 15. the return a means that whatever value a is, the function will send it back
to the main.

now for the second function, the purpose is to show how the change in the seed number, from 1 to 11, will change the output.
The third function shows if i kept the seed the same, the same output will be delivered.
*/
