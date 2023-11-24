/*
ID: polaric2
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define DECODE(x) (x-'A'+1)

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    int t[2];

    for(int i=0;i<2;i++) {
        string s;
        fin >> s;
        t[i] = 1;
        for (char& c :s) {
            t[i] = (t[i]*DECODE(c)) % 47;
        }
    }

    if (t[0] == t[1])
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}