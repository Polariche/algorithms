/*
ID: polaric2
TASK: ttwo
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

bool a[12][12];

int cv[12][12][4] = {0};
int fv[12][12][4] = {0};

int dir_ij[4][2] = {{-1,0},{0,1},{1,0},{0, -1}};

int move(int * i, int * j, int * dir, int v[12][12][4]) {
    int d = *dir;
    int t = v[*i][*j][d];
    
    int i_ = *i+dir_ij[d][0];
    int j_ = *j+dir_ij[d][1];

    if (a[i_][j_]) {
        *i = i_;
        *j = j_;

        if (v[i_][j_][d] > 0) return 1;
        v[i_][j_][d] = t+1;

    } else {
        *dir = (d+1)%4;
    }

    return 0;
}

int main() {
    ofstream cout ("ttwo.out");
    ifstream cin ("ttwo.in");

    int ci, cj, cd=0, fi, fj, fd=0;
    char c;
    int cnt=0;
    for (int i=0;i<=11;i++) {
        a[i][0] = a[i][11] = 0;
        
        if (i==0 || i == 11) {
            continue;
        }
        
        for (int j=1;j<=10;j++) {
            cin >> c;
            a[i][j] = (c != '*');
            cnt+= a[i][j];

            if (c == 'C') {ci = i; cj = j; cv[i][j][0] = 1;}
            if (c == 'F') {fi = i; fj = j; fv[i][j][0] = 1;}
            
        }
    }

    int t;
    int found = 0;
    for (t=1;t<=4*cnt;t++) {
        move(&ci, &cj, &cd, cv);
        move(&fi, &fj, &fd, fv);

        if (ci==fi && cj==fj) {
            cout << t << endl;
            found = 1;
            break;
        }
    }
    
    if (!found) cout << 0 << endl;

    return 0;
}