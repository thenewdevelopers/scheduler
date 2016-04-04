#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(void)
{
    fstream inputFile;
    string s1, s2, s3;

    inputFile.open("input.txt");
    while (inputFile >> s1 >> s2 >> s3) {
        cout << "s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << endl;
    }
    inputFile.close();

    return(0);
}
