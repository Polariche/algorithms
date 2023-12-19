/*
ID: polaric2
TASK: nocows
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

#define MOD 9901

int dp[201][101];

int solve(int n, int k) {
    if (n<1 || (k < 31 && n>>k > 0) || n < 2*k-1)    return 0;
    if (n==1 && k==1) return 1;
    if (dp[n][k] > -1)  return dp[n][k];

    dp[n][k] = 0;
    for (int i=1;i<=n/2;i+=2) {
        int j = n-i-1;

        int x=0, x_;
        for (int a=1;a<k-1;a++)
            x += solve(i,a);
        x_ = solve(i,k-1);

        x %= MOD;
        x_%= MOD;

        if (!(x+x_))    continue;

        if (i==j) {
            dp[n][k] += (x_*x_ + 2*x*x_) % MOD;
            dp[n][k] %= MOD;
        } else {
            int y=0, y_;
            for (int a=1;a<k-1;a++)
                y += solve(j,a);
            y_ = solve(j,k-1);

            y %= MOD;
            y_ %= MOD;
            
            dp[n][k] += (2*(x_*y_ + x_*y + x*y_)) % MOD;
            dp[n][k] %= MOD;
        }
    }

    cout << n << " " << k << " " << dp[n][k] << endl;
    return dp[n][k];
}

int main() {
    ofstream cout ("nocows.out");
    ifstream cin ("nocows.in");

    int n,k;
    cin >> n >> k;

    for(int i=1;i<=200;i++) {
        for (int j=2;j<100;j++) 
            dp[i][j] = -1;
    }

    for (int j=2;j<k;j++) {
        for (int i=2*j-1;i<n;i+=2)
            solve(i, j);
    }

    cout << solve(n,k) << endl;

    return 0;
}