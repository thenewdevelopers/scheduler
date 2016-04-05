#include <iostream>
#include <cstdlib>
using namespace std;

int main (){
string COLS;
int people = 15, ROWS = 15;
string Schedule [people][20];
int Hours [20][20];
int p = 1;
Schedule [0][0] = "      ";
Schedule [0][1] = "Sunday";
Schedule [0][2] = "Monday";
Schedule [0][3] = "Tuesday";
Schedule [0][4] = "Wednesday";
Schedule [0][5] = "Thursday";
Schedule [0][6] = "Friday";
Schedule [0][7] = "Saturday";



for(int i = 0; i < people; i++)
{ for(int j = 0; j < 8; j++)
    {
        if (i == 0 && j == 0)
        {cout <<"        ";}

        else if (j == 0 && p<10)
        {cout <<endl << Schedule[i][j] << "Person" << p << "  ";
         p++;}

         else if (j == 0 && p>=10)
        {cout <<endl << Schedule[i][j] << "Person" << p << " ";
         p++;}


        else if (i == 0) cout << Schedule[i][j] << " ";
        else{
            Hours[i][j] = rand()%9+1;
            if (Hours[i][j]>=1 || Hours[i][j]<=9)
                {cout << Hours[i][j] << "       ";}
            else
           {cout << Hours[i][j] << " ";}

                                }


        }
    }







return 0;
}
