
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;




int main(){

ofstream outputFile;
outputFile.open("William's info.txt"); //this part will create its own file if you do not have a file named inputpractice.txt
//I think at this point i can create an ifelse statment. Inside the open(), i think i can input a variable by the name of the person. If there is a file associated with
//this person, it will just pull it. If not, then a file will be created. OOOOOOOOOr when can come up with another part that tells the new user to go there and
//create their own file.

string NameOfEmployeeLast, NameOfEmployeeFirst, NameOfPosition;
double PayPerHour;

cout << "What is your first name? " << endl << "First name: ";
cin >> NameOfEmployeeFirst;
system("cls");

cout << "What is your last name? " << endl << "Last Name: ";
cin >> NameOfEmployeeLast;
system("cls");

cout << "What is your position? " << endl << "Position: "; //At this point, the position needs to be only one word. If the input is two words, the second word will go
cin >> NameOfPosition;                                     //to the payperhour variable
system("cls");

cout << "What is your dollars per hour? " << endl << "Payrate: ";
cin >> PayPerHour;
system("cls");

cout << "Your first name is " << NameOfEmployeeFirst << endl;
cout << "Your last name is " << NameOfEmployeeLast << endl;
cout << "Your position is " << NameOfPosition << endl;
cout << "Your pay rate is " << PayPerHour << endl;

outputFile << NameOfEmployeeFirst << endl;
outputFile << NameOfEmployeeLast <<endl;
outputFile << NameOfPosition << endl;
outputFile << PayPerHour << endl;

outputFile.close();
cout << "Done!" <<endl;//checks to see if the file was inputed and all that fun stuff



return 0;
}
