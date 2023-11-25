/*
ID: polaric2
TASK: dualpal
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;



int main() {
    ofstream cout ("dualpal.out");
    ifstream cin ("dualpal.in");
    
    int n, s, cnt=0;
    cin >> n >> s;
    s++;

    while (cnt < n) { // O (???)
        int tick=0;

        for (int i=2;i<=10;i++) {
            int a=s, k=0, l=0;
            int t[100];

            while(a) {  // O(log n)
                t[k++] = a%i;  
                a/=i;
            }

            for(l=0;l<k/2;l++) {
                if (t[l] != t[k-l-1]) break;
            }
            if (l == k/2) tick++;
            if (tick >= 2)  {
                // we've found a dual palindrome
                cnt++;
                cout << s << endl;
                break;
            }
        }
        s++;
    }

    return 0;
}