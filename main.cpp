#include <iostream> //preprocessor directive
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
		int currentworkedhoursfortheweek;
		
	public: //access specifier
		//classObjectConstructor with parameters
		EmployeeClass(string firstNameHere, string positionHere, float hourlyWageHere, int maxDayHoursHere, int maxWeekHoursHere, int workedHoursHere){
			firstname = firstNameHere;
			position = positionHere;
			hourlywage = hourlyWageHere;
			maxdayhours = maxDayHoursHere;
			maxweekhours = maxWeekHoursHere;
			currentworkedhoursfortheweek = workedHoursHere;
			bool offdays[7] = {false, true, true, true, true, true, false};
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
		
		int WorkedHours(){
			return currentworkedhoursfortheweek;
		}
};

//print function like in java
void print(string text){
	cout<<text;
}
//print on one line function like in java
void println(string text){
	cout<<text<<endl;
}

//Main program
int main(){ 
	
	EmployeeClass person0("James", "backend", 9.00, 8, 40, 0);//these are just temporary. we will use files created by the users to input the employees
	EmployeeClass person1("Jennie", "frontend", 8.00, 8, 28, 0);//
	EmployeeClass person2("William", "backend", 9.00, 8, 28, 0);//
	EmployeeClass person3("Dakota", "frontend", 8.00, 8, 28, 0);//
	EmployeeClass person4("Pam", "frontend", 12.00, 8, 40, 0);//
	EmployeeClass person5("Katie", "manager", 10.00, 8, 28, 0);//
	EmployeeClass person6("Michelle", "manager", 14.00, 8, 48, 0);//
	EmployeeClass person7("Janet", "backend", 10.00, 8, 40, 0);//
	EmployeeClass person8("Justin", "manager", 15.00, 8, 48, 0);//
	EmployeeClass person9("Andy", "manager", 25.00, 8, 70, 0);//
	
	EmployeeClass employeelist[10] = {person0, person1, person2, person3, person4, person5, person6, person7, person8, person9 };
	
	srand(time(0));
	int shift = 0;	// "0" is for opening manager, "1" is for opening backend, "2" is for opening cashier, "3" is for mid backend #1, "4" is for mid backend #2, "5" is for closing manager, "6" is for closing backend, "7" is for closing cashier 
	int managersworking = 0;
	int cashiersworking = 0;
	int backendworking = 0;
	int availablepeoplefortheday = 8;
	for(int a = 0; a < 1; a++){//this loop is important for later
	
	//a single day for a work week made of an array that will have all the people working for that day that will be printed out
	string Day[8];
	
		//This is the first shift loop that adds people for that shift
		while(shift <=2){
			//random index of employeelist array and a variable/pointer that just tells the computer which person is being used. it isnt a copy like a normal variable
			EmployeeClass *exactemployeeobject = &employeelist[rand()%10];
			
			switch(shift){
				
				//opening shift assignment
/*###*/		case 0: 
				
				//adds manager to the "Day" array at index of 0
				if(managersworking != 1 && exactemployeeobject->Position() == "manager"){
					Day[0] = exactemployeeobject->Name();
					managersworking++;
					cout<<exactemployeeobject->Name()<<endl;
				}
				
				//adds backend team member to the "Day" array at index of 1 
				else if(backendworking != 1 && exactemployeeobject->Position() == "backend"){
					Day[1] = exactemployeeobject->Name();
					backendworking++;
					cout<<exactemployeeobject->Name()<<endl;
				}
				
				//adds cashier to the "Day" array at index 2
				else if(cashiersworking != 1 && exactemployeeobject->Position() == "frontend"){
					Day[2] = exactemployeeobject->Name();
					cashiersworking++;
					cout<<exactemployeeobject->Name()<<endl;
				}
				
				// ends opening shift assignment
				if(cashiersworking == 1 && managersworking == 1 && backendworking == 1){
					cout<<"finished";
					int managersworking = 0;
					int cashiersworking = 0;
					int backendworking = 0;
					shift++;
				}
				
				break;
				
/*###*/		case 1:
					break;
					
/*###*/		case 2:
					break;
				
			}
			
		}
	}
}
	
	




