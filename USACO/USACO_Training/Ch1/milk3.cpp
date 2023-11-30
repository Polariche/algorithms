/*
ID: polaric2
TASK: milk3
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string.h>
using namespace std;

#define check(a,b) dp[a*(B+1) + b]
typedef long long ll;
int A,B,C;

int solve(int a, int b, int* dp) {
    if (check(a,b))
        return 0;

    int x;
    int c = C-(a+b);
    
    check(a,b) = 1;

    if (a > 0) {
        // A -> B
        x = min(a, B-b);
        solve(a-x, b+x, dp);

        // A -> C
        x = min(a, C-c);
        solve(a-x, b, dp);
    }
        
    if (b > 0) {
        // B -> A
        x = min(b, A-a);
        solve(a+x, b-x, dp);

        // B -> C
        x = min(b, C-c);
        solve(a, b-x, dp);
    }
    
    if (c > 0) {
        // C -> A
        x = min(c, A-a);
        solve(a+x, b, dp);

        // C -> B
        x = min(c, B-b);
        solve(a, b+x, dp);
    }

    return 1;
}

int main() {
    ofstream cout ("milk3.out");
    ifstream cin ("milk3.in");

    cin >> A >> B >> C;

    int dp[(A+1)*(B+1)]={0};

    solve(0,0,dp);

    int cnt=0;
    for (int c=0;c<=C;c++) {
        if (check(0,C-c) && C-c <= B) {
            if (cnt++) cout << " ";
            cout << c;
        }
    }
    cout << endl;

    return 0;
}