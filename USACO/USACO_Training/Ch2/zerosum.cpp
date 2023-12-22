/*
ID: polaric2
TASK: zerosum
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pi;

int solve(char * s, int n) {
    int sum = 0;
    int next = 1;
    int sign = 1;
    for (int i=1;i<2*n;i+=2) {
        switch(s[i]) {
            case ' ': next = next*10 + s[i+1]-'0'; break;
            case '+': sum += next * sign; next = s[i+1]-'0'; sign = 1; break;
            case '-': sum += next * sign; next = s[i+1]-'0'; sign = -1; break;
            case '\0': sum += next * sign; break;
        }
    }
    return !sum;
}

int make(char* s, int n, ofstream * cout) {
    int sum=0;
    char c[4] = " +-";
    if (s[1] == '\0') {
        int ans = solve(s-(2*n-2), n);
        if (ans) {
            *cout << s-(2*n-2) << endl;
        }
        return ans;
    }
        
    for (int i=0;i<3;i++) {
        s[1] = c[i];
        sum += make(s+2, n, cout);
    }
    return sum;
}

int main() {
    ofstream cout ("zerosum.out");
    ifstream cin ("zerosum.in");

    int n;
    cin >> n;

    char s[18] = "1 2 3 4 5 6 7 8 9";
    s[2*n-1] = '\0';
    
    make(s, n, &cout);

    return 0;
}