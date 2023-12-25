/*
ID: polaric2
TASK: cowtour
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

int n;
pi p[150];
bool adj[150][150];
float len[150][150];
bool v[150] = {0};

int find(int i) {
    if (v[i])   return 0;
    v[i] = 1;

    for (int j=0;j<n;j++) {
        if (adj[i][j]) {
            find(j);

            for (int k=0;k<n;k++) {
                if (adj[j][k] && !adj[i][k])
                    len[i][k] = min(len[i][j] + len[j][k], len[i][k]);
            }
            
        }
    }
    return 1;
}

int main() {
    ofstream cout ("cowtour.out");
    ifstream cin ("cowtour.in");

    cin >> n;

    for (int i=0;i<n;i++)
        cin >> p[i].first >> p[i].second;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            char c;
            cin >> c;
            adj[i][j] = c=='1';
            if (i==j)   continue;

            if (adj[i][j]) 
               len[i][j] = sqrt(pow(p[i].first - p[j].first,2) + pow(p[i].second - p[j].second,2));
            else
               len[i][j] = 100000 * sqrt(2);
        } 
    }

    for (int i=0;i<n;i++)
        find(i);

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << len[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}