/*
ID: polaric2
TASK: money
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
#include <iterator>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pi;

#define M 26

void deduct(int v, int n, int m[M], int cnt[M]) {
    for (int i=v;i>0;i--) {
        cnt[i] = n/m[i];
        n %= m[i];
    }
}

int solve(int i, int cnt[M], int vcnt[M][M]) {
    if (i==0)   return 0;
    else if (i==1) {for(int j=1;j<=3;j++) cout << cnt[j] << " "; cout << endl; return 1;}

    int a = 0;

    int original[M];
    copy(cnt, cnt+M, original);
    for (;cnt[i]>=0;cnt[i]--) {
        a += solve(i-1, cnt, vcnt);
        for (int j=i-1;j>0;j--)
            cnt[j] += vcnt[i][j];
    }
    copy(original, original+M, cnt);
    return a;
}

int main() {
    ofstream cout ("money.out");
    ifstream cin ("money.in");

    int v,n;
    int m[M], cnt[M], vcnt[M][M];
    map<int,int> rep;
    cin >> v >> n;

    for (int i=1;i<=v;i++) {
        cin >> m[i];
    }
        

    sort(m, m+v);

    deduct(v, n, m, cnt);
    for (int i=v;i>0;i--)
        deduct(i-1, m[i], m, vcnt[i]);

    for (int i=v;i>0;i--) {
        cout << cnt[i];
        for (int j=i-1;j>0;j--) {
            cout << " " << vcnt[i][j];
        }
        cout << endl;
    }

    cout << solve(v, cnt, vcnt) << endl;

    return 0;
}