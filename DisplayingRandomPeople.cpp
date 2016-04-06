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


	int shift = 0;
string shiftOne[10][10];
string shiftTwo[10][10];
string shiftThree[10][10];
	srand(2);
int numberOfWorkers = 8;

int number;
	for(int j = 0; j < 8; j++){
        int managersworking = 0;
		int cashiersworking = 0;
		int backendworking = 0;
        for(int i = 0; i <numberOfWorkers; i=i){
            number = rand()%10;

		string test = employeelist[number].Position();
        string nameOfEmployee = employeelist[number].Name();
		//add managers to first shift
		if(test == "manager" && managersworking == 0){
			//cout<<test <<" " << nameOfEmployee<<endl;
			managersworking++;
			shiftOne[j][0] = nameOfEmployee;
            i++;
		}//add backend team meamber to first shift
		else if(test== "backend" && backendworking ==0){
			//cout<<test << " " << nameOfEmployee<<endl;
			backendworking++;
			shiftOne[j][1] = nameOfEmployee;
            i++;
		}//add cashier to first shift
		else if(test == "frontend" && cashiersworking == 0){
			//cout<<test <<" " << nameOfEmployee<<endl;
			cashiersworking++;
			shiftOne[j][2] = nameOfEmployee;
            i++;


		}
		else if(test== "backend" && backendworking == 1 && nameOfEmployee != shiftOne[j][0] && nameOfEmployee != shiftOne[j][1] && nameOfEmployee != shiftOne[j][2]){
			//cout<<test << " " << nameOfEmployee<<endl;
			backendworking++;
			shiftTwo[j][3] = nameOfEmployee;
            i++;
		}
		else if(test == "frontend" && cashiersworking == 1 && nameOfEmployee != shiftOne[j][0] && nameOfEmployee != shiftOne[j][1] && nameOfEmployee != shiftOne[j][2]){
			//cout<<test <<" " << nameOfEmployee<<endl;
			cashiersworking++;
			shiftTwo[j][4] = nameOfEmployee;
            i++;
        }
        else if(test == "manager" && managersworking == 1 && nameOfEmployee != shiftOne[j][0] && nameOfEmployee != shiftOne[j][1] && nameOfEmployee != shiftOne[j][2]){
			//cout<<test <<" " << nameOfEmployee<<endl;
			managersworking++;
			shiftThree[j][5] = nameOfEmployee;
            i++;
            }
        else if(test== "backend" && backendworking ==2 && nameOfEmployee != shiftOne[j][0] && nameOfEmployee != shiftOne[j][1] && nameOfEmployee != shiftOne[j][2] && nameOfEmployee != shiftTwo[j][3]&& nameOfEmployee != shiftTwo[j][4] ){
			//cout<<test << " " << nameOfEmployee<<endl;
			backendworking++;
			shiftThree[j][6] = nameOfEmployee;
            i++;
		}
		else if(test == "frontend" && cashiersworking == 2 && nameOfEmployee != shiftOne[j][0] && nameOfEmployee != shiftOne[j][1] && nameOfEmployee != shiftOne[j][2] && nameOfEmployee != shiftTwo[j][3]&& nameOfEmployee != shiftTwo[j][4] ){
			//cout<<test <<" " << nameOfEmployee<<endl;
			cashiersworking++;
			shiftThree[j][7] = nameOfEmployee;
            i++;

		}
	}
	}
	/*for(int j = 0; j < 8; j++){
        for(int i = 0; i <=7; i++){
                cout << shiftOne[j][i]<< shiftTwo[j][i]<<shiftThree[j][i]<<endl;}
                cout <<"==========================="<< endl;*/
	//if you were to under this and run it, it will not work because the thing above does not place the names
	//in order like i originally thought
	for(int j = 0; j < 8; j++){
            cout << "First Shift People " << endl;
        for(int i = 0; i <=2; i++){
                cout << shiftOne[j][i]<< endl;}

            cout << endl << "Second Shift People: " << endl;
        for(int i = 3; i <=4; i++){
                cout << shiftTwo[j][i]<< endl;}

            cout << endl << "Third Shift People: " << endl;
        for(int i = 5; i <=7; i++){
                cout << shiftThree[j][i]<< endl;}

        cout << "==============" <<endl;}


	return 0;
}
