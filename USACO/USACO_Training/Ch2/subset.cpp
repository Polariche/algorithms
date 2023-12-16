/*
ID: polaric2
TASK: subset
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


ll dp[40][781];

ll solve(int x, int s) {
    if (x < 0 || s < 0)     return 0;
    else if (x == 0 && s == 0)    return 1;

    if (dp[x][s] >= 0) return dp[x][s];

    dp[x][s] = solve(x-1, s-x) + solve(x-1, s);

    return dp[x][s];
}

int main() {
    ofstream cout ("subset.out");
    ifstream cin ("subset.in");

    int N;
    cin >> N;

    for (int x=0;x<=39;x++) {
        for (int s=0;s<=780;s++)
            dp[x][s] = -1;
    }

    if ((N*(N+1)/2)%2) 
        cout << 0 << endl;
    else
        cout << solve(N, N*(N+1)/4) / 2 << endl;
    
    return 0;
}