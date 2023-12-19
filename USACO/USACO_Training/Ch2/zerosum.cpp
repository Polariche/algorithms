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


int dp[10];

int solve(int n) {
    if (dp[n] >= 0) return dp[n];

    

    return dp[n];
}

int main() {
    ofstream cout ("zerosum.out");
    ifstream cin ("zerosum.in");

    int n;
    cin >> n;

    for (int i=0;i<=9;i++) 
        dp[i] = -1;
    
    for (int i=0;i<=n;i++)
        solve(i);
    
    cout << dp[n] << endl;

    return 0;
}