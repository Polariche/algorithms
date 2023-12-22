/*
ID: polaric2
TASK: concom
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

int a[101][101];
int b[101][101];
bool v[101][101];
vector<int> owns[101];
vector<int> nowns[101];

vector<pi> answers;

int dfs(int i, int m);
int visit(int i, int j, int m) {
    if (v[i][j]) return 0;
    v[i][j] = 1;

    //cout << "visit " << i << " " << j << endl;

    dfs(j, m);

    for (int k=1;k<=m;k++) {
        if (i==k || j==k) continue;
        b[i][k] += a[j][k];

        if (b[i][k] - a[j][k] < 50 && b[i][k] >= 50)   {
            if (visit(i,k,m)) 
                owns[i].push_back(k);
        } 
    }
    return 1;
}

int dfs(int i, int m) {
    if (v[i][i]) return 0;
    v[i][i] = 1;

    //cout << "dfs " << i << endl;

    for (int & j : owns[i]) {
        visit(i,j,m);
    }

    for (int & j : nowns[i]) {
        if (b[i][j] >= 50) {
            
            if (visit(i,j,m))
                owns[i].push_back(j);
        }
    }

    for (int &j : owns[i]) {
        if (i==j) cout << i << endl;
        answers.push_back(pi(i,j));
    }
    
    return 1;
}

int main() {
    ofstream cout ("concom.out");
    ifstream cin ("concom.in");

    int n, m=0;
    cin >> n;

    for (int i=1;i<=100;i++) {
        for (int j=1;j<=100;j++) {
            a[i][j] = b[i][j] = v[i][j] = 0;
        }  
    }
    
    for (int t=0;t<n;t++) {
        int i,j,k;
        cin >> i >> j >> k;
        a[i][j] = b[i][j] = k;

        if (k>=50 && i!=j)  owns[i].push_back(j);

        m = max(max(i,j),m);
    }

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=m;j++)
            if (a[i][j] < 50 && i!=j)   nowns[i].push_back(j);
    }

    for (int i=1;i<=m;i++) {
        dfs(i, m);
    }
        
    sort(answers.begin(), answers.end());
    for (auto &[i,j] : answers)
        cout << i << " " << j << endl;

    return 0;
}