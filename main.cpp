#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class EmployeeClass{
	
	private: //access specifier
		string firstname;
		string position;
		float hourlywage;
		int maxdayhours;
		int mindayhours;
		int maxweekhours;
		int minweekhours;
		
	public: //access specifier
		//classObjectConstructor
		EmployeeClass(string firstNameHere, string positionHere, float hourlyWageHere, int maxDayHoursHere, int maxWeekHoursHere){
			firstname = firstNameHere;
			position = positionHere;
			hourlywage = hourlyWageHere;
			maxdayhours = maxDayHoursHere;
			maxweekhours = maxWeekHoursHere;
			bool offdays[7] = {false, true, true, true, true, true, false};
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
};

//print function like in java
void print(string text){
	cout<<text;
}
//print on one line function like in java
void println(string text){
	cout<<text<<endl;
}

int main(){
	
	EmployeeClass person0("James", "backend", 9.00, 8, 40);//
	EmployeeClass person1("Jennie", "frontend", 8.00, 8, 28);//
	EmployeeClass person2("William", "backend", 9.00, 8, 28);//
	EmployeeClass person3("Dakota", "frontend", 8.00, 8, 28);//
	EmployeeClass person4("Pam", "frontend", 12.00, 8, 40);//
	EmployeeClass person5("Katie", "manager", 10.00, 8, 40);//
	EmployeeClass person6("Michelle", "backend", 14.00, 8, 48);//
	EmployeeClass person7("Janet", "backend", 10.00, 8, 40);//
	EmployeeClass person8("Justin", "manager", 15.00, 8, 48);//
	EmployeeClass person9("Andy", "manager", 25.00, 8, 70);//
	
	EmployeeClass employeelist[10] = {person0, person1, person2, person3, person4, person5, person6, person7, person8, person9 };
	
	srand(time(0));
	
	int shift = 0;	
	int managersworking = 0;
	int cashiersworking = 0;
	int backendworking = 0;
	
	for(int i = 0; i <= 2; i = i){
		// random index of employeelist array
		EmployeeClass *tester = &employeelist[rand()%10];
		//add managers to first shift
		if(tester->Position() == "manager" && managersworking != 1){
			cout<<tester->Position() + " ";
			cout<<tester->Name() <<endl;
			managersworking = 1;
			i++;
		}//add backend team meamber to first shift
		else if(tester->Position() == "backend" && backendworking != 1){
			cout<<tester->Position() + " ";
			cout<<tester->Name() <<endl;
			backendworking = 1;
			i++;
		}//add cashier to first shift
		else if(tester->Position() == "frontend" && cashiersworking != 1){
			cout<<tester->Position() + " ";
			cout<<tester->Name() <<endl;
			cashiersworking = 1;
			i++;
		}
	}
	return 0;
}











