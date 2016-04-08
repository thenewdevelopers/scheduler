#include <iostream> //preprocessor directive
#include <string> //preprocessor directive
#include <cstdlib> //preprocessor directive
#include <ctime> //preprocessor directive
using namespace std; //standard library

class EmployeeClass{
	private: //access specifier
		string firstname;
		string position;
		float hourlywage;
		int maxdayhours;
		int mindayhours;
		int maxweekhours;
		int minweekhours;
		float currentworkedhoursfortheweek;
		bool alreadyworking;
	public: //access specifier
		//classObjectConstructor with parameters
		EmployeeClass(string firstNameHere, string positionHere, float hourlyWageHere, int maxDayHoursHere, int maxWeekHoursHere, int workedHoursHere, bool alreadyWorkingHere){
			firstname = firstNameHere;
			position = positionHere;
			hourlywage = hourlyWageHere;
			maxdayhours = maxDayHoursHere;
			maxweekhours = maxWeekHoursHere;
			currentworkedhoursfortheweek = workedHoursHere;
			bool offdays[7] = {false, true, true, true, true, true, false};
			alreadyworking = alreadyWorkingHere;
		}	
		//classObjectConstructor without parameters
		EmployeeClass(){
			
		}
		string Name(){
			return firstname;
		}
		string Position(){
			return position;
		}
		float Wage(){
			return hourlywage;
		}
		int MaxDayHours(){
			return maxdayhours;
		}
		int MaxWeekHours(){
			return maxweekhours;
		}
		float AddWorkedHours(float x){
			currentworkedhoursfortheweek += x;
		}
		int WorkedHours(){
			return currentworkedhoursfortheweek;
		}
		bool AlreadyWorkingCheck(){
				return alreadyworking;
		}
		bool AlreadyWorking(bool x){ //this is so i can change if that person is working already or not
			alreadyworking = x;
		}
};
//Main program
int main(){ 
	EmployeeClass person0("James", "backend", 9.00, 8, 40, 0, false);//these are just temporary. we will use files created by the users to input the employees
	EmployeeClass person1("Jennie", "frontend", 8.00, 8, 28, 0, false);//
	EmployeeClass person2("William", "backend", 9.00, 8, 28, 0, false);//
	EmployeeClass person3("Dakota", "frontend", 8.00, 8, 28, 0, false);//
	EmployeeClass person4("Pam", "frontend", 12.00, 8, 40, 0, false);//
	EmployeeClass person5("Katie", "manager", 10.00, 8, 28, 0, false);//
	EmployeeClass person6("Michelle", "manager", 14.00, 8, 48, 0, false);//
	EmployeeClass person7("Janet", "backend", 10.00, 8, 40, 0, false);//
	EmployeeClass person8("Justin", "manager", 15.00, 8, 56, 0, false);//
	EmployeeClass person9("Andy", "manager", 25.00, 8, 70, 0, false);//
	EmployeeClass person10("Thomas", "backend", 10.00, 8, 40, 0, false);//
	EmployeeClass person11("Shawme", "frontend", 8.00, 8, 28, 0, false);//
	EmployeeClass person12("A.J.", "backend", 9.00, 8, 28, 0, false);//
	EmployeeClass person13("Garret", "backend", 9.00, 8, 28, 0, false);//
	EmployeeClass person14("Davon", "manager", 10.00, 8, 40, 0, false);//
	EmployeeClass person15("Clayton", "backend", 9.00, 8, 28, 0, false);//
	EmployeeClass employeelist[16] = {person0, person1, person2, person3, person4, person5, person6, person7, person8, person9, person10, person11, person12, person13, person14, person15};
	srand(time(0));
	int shift = 0;	// "0" is for opening manager, "1" is for opening backend, "2" is for opening cashier, "3" is for mid backend #1, "4" is for mid backend #2, "5" is for closing manager, "6" is for closing backend, "7" is for closing cashier 
	int managersworking = 0;
	int cashiersworking = 0;
	int backendworking = 0;
	int availablepeoplefortheday = 8;
	for(int a = 0; a < 7; a++){//this loop is important for later
		//turns already working to false 
		for(int z = 0; z < 16; z++){
			employeelist[z].AlreadyWorking(false);
		}
		shift = 0;	// "0" is for opening manager, "1" is for opening backend, "2" is for opening cashier, "3" is for mid backend #1, "4" is for mid backend #2, "5" is for closing manager, "6" is for closing backend, "7" is for closing cashier 
		managersworking = 0;
		cashiersworking = 0;
		backendworking = 0;
		//a single day for a work week made of an array that will have all the people working for that day that will be printed out
		string Day[8];
		//This is the first shift loop that adds people for that shift
		while(shift <=2){
			//random index of employeelist array and a variable/pointer that just tells the computer which person is being used. it isnt a copy like a normal variable
			EmployeeClass* exactemployeeobject = &employeelist[rand()%16];
			switch(shift){
				//opening shift assignment
/*###*/		case 0: 
					//adds manager to the "Day" array at index of 0
					if(managersworking < 1 && exactemployeeobject->Position() == "manager" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() <(exactemployeeobject->MaxWeekHours())){
						Day[0] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						managersworking++;
						cout<<exactemployeeobject->Name() + " " + "7-3" <<endl;
					}
					//adds backend team member to the "Day" array at index of 1 
					else if(backendworking < 1 && exactemployeeobject->Position() == "backend" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < (exactemployeeobject->MaxWeekHours() - 8)){
						Day[1] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						backendworking++;
						cout<<exactemployeeobject->Name() + " " + "7-3" <<endl;
					}
					//adds cashier to the "Day" array at index 2
					else if(cashiersworking < 1 && exactemployeeobject->Position() == "frontend" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < (exactemployeeobject->MaxWeekHours() - 8)){
						Day[2] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						cashiersworking++;
						cout<<exactemployeeobject->Name() + " " + "7-3" <<endl;
					}
					// ends opening shift assignment
					if(cashiersworking == 1 && managersworking == 1 && backendworking == 1){
						shift++;
						managersworking = 0;
						cashiersworking = 0;
						backendworking = 0;
					}
					break;
/*###*/		case 1:
					//adds backend team member to the "Day" array at index of 3
					if(backendworking == 0 && exactemployeeobject->Position() == "backend" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < (exactemployeeobject->MaxWeekHours() - 8)){
						Day[3] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						cout<<exactemployeeobject->Name() + " " + "10-6" <<endl;
						backendworking++;
					}
					if(managersworking < 1 && exactemployeeobject->Position() == "manager" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() <(exactemployeeobject->MaxWeekHours())){
						Day[0] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						managersworking++;
						cout<<exactemployeeobject->Name() + " " + "7-3" <<endl;
					}
					//adds backend team member to the "Day" array at index of 4
					else 	if(backendworking == 1 && exactemployeeobject->Position() == "backend" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < (exactemployeeobject->MaxWeekHours() - 8)){                      
						Day[4] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						cout<<exactemployeeobject->Name() + " " + "10-6" <<endl;
						backendworking++;
					}
					// ends opening shift assignment
					if(backendworking == 2){
						shift++;
						managersworking = 0;
						cashiersworking = 0;
						backendworking = 0;
					}
					break;
/*###*/		case 2:
					//adds manager to the "Day" array at index of 0
					if(managersworking < 1 && exactemployeeobject->Position() == "manager" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < exactemployeeobject->MaxWeekHours()){
						Day[5] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						cout<<exactemployeeobject->Name() + " " + "1-9" <<endl;
						managersworking++;
					}
					//adds backend team member to the "Day" array at index of 6
					else if(backendworking < 1 && exactemployeeobject->Position() == "backend" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < (exactemployeeobject->MaxWeekHours() - 8)){
						Day[6] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						cout<<exactemployeeobject->Name() + " " + "1-9" <<endl;
						backendworking++;
					}
					//adds cashier to the "Day" array at index 7
					else if(cashiersworking < 1 && exactemployeeobject->Position() == "frontend" && exactemployeeobject->AlreadyWorkingCheck() != true && exactemployeeobject->WorkedHours() < (exactemployeeobject->MaxWeekHours() - 8)){
						Day[7] = exactemployeeobject->Name();
						exactemployeeobject->AlreadyWorking(true);
						exactemployeeobject->AddWorkedHours(7.5);
						cout<<exactemployeeobject->Name() + " " + "1-9" <<endl;
						cashiersworking++;
					}
					// ends opening shift assignment
					if(cashiersworking == 1 && managersworking == 1 && backendworking == 1){
						shift++;
						managersworking = 0;
						cashiersworking = 0;
						backendworking = 0;
						cout<<endl;
					}
					break;
			}
		}
	}
	//show how many hours each person has worked for the week
	for(int x = 0; x < 16; x++){
		cout << employeelist[x].Name() << " " << employeelist[x].WorkedHours() << endl;
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
	
	




