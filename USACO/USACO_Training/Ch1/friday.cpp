/*
ID: polaric2
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MON 0
#define TUE 1
#define WED 2
#define THU 3
#define FRI 4
#define SAT 5
#define SUN 6

#define MOD(x) ((x)%7)

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;
    int d = MON;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int cnt[7] = {0,0,0,0,0,0,0};
    
    
    fin >> N;

    for (int i=1900;i<1900+N;i++) {
        bool leap = (!(i%4) && (i%100)) || !(i%400);
        days[1] += leap;
        for (int j=0;j<12;j++) {
            cnt[MOD(d + 12)]++;
            d = MOD(d + days[j]);
        }
        days[1] -= leap;
    }

    for (int i=0;i<7;i++) {
        fout << cnt[(i+5)%7] << (i==6? "" : " ");
    }
    fout << endl;
    return 0;
}