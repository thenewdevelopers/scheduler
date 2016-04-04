#include <iostream>
#include <cstdlib>
#include <ctime> //these two directories go hand and hand with one another
                 //the ctime always you to use the srand.
                 //the cstdlib allows you to use rand
using namespace std;

int main(){
int a,b,c;


srand(time(0));

for (int j = 0; j <10; j++){
a = rand()%10;
b = rand()%10;


for (int i = 0; i < 1; i++)
{cout << "a= " << a << "b= " << b <<endl;}


}


return 0;
}
