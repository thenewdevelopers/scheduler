#include <iostream>
#include <cstdlib>

using namespace std;


int main(){
int countNumberOfElements = 0;
int countOfZeros = 0;
int countOfNumbers = 0;
int a[5000]; //this tells the user/compiler how many elements are in this array. Not all elements have to be filled,
             //this is called partial array, and used to just overkill the amount of elements so the programmer
             //does not have to worry about changing it



for (int i = 0; i <50; i++) //this will place a random number between 1 and 50 into an element i. if i=9, a random
                            //number will be placed in element 9 of the array
{
a[i]= rand()%50+1;

}
for (int j = 0; j<60; j++){ //This displays elements 0-59 (adding up to 60. the counting of arrays start at zero)
                            //you see that I only placed numbers to 49, the remaining will be zero's
cout << a[j] << endl;
countNumberOfElements++;}
for (int k = 0; k < 60; k++){//this part will count the zero's and actual numbers for each element. later, it will be displayed
if (a[k]==0)
    countOfZeros++;
else
    countOfNumbers++;

}
cout << "Number of elements: " <<countNumberOfElements <<endl;
cout << "Number of actual numbers: " << countOfNumbers << endl;
cout << "Number of Zeros: " << countOfZeros <<endl;
return 0;
}
