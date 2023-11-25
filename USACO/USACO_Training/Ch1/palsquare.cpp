/*
ID: polaric2
TASK: palsquare
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;



int main() {
    ofstream cout ("palsquare.out");
    ifstream cin ("palsquare.in");
    
    int n;
    cin >> n;

    for (int i=1;i<=300;i++) {
        char t[18], t2[18];
        int j, k=0;
        int a = i*i;

        // this is reversed, but it's supposed to be palendromic so doesn't matter
        while (a) {
            t[k++] = (a%n) + ((a%n)>9? 'A'-10 : '0');
            a/=n;
        }
        t[k] = '\0';

        for (j=0;j<k/2;j++) {
            if(t[j] != t[k-1-j]) break;
        }

        if (j==k/2) {
            a = i;
            k=0;
            
            while (a) {
                t2[k++] = (a%n) + ((a%n)>9?  'A'-10 : '0');
                a/=n;
            }
            t2[k] = '\0';

            reverse(t2, t2+k);

            cout << t2 << " " << t << endl;
        }

    }

    return 0;
}