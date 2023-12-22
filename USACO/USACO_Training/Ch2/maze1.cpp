/*
ID: polaric2
TASK: maze1
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


int dirs[4][2] = {{-1,0},{0,1},{1,0},{0, -1}};


int main() {
    ofstream cout ("maze1.out");
    ifstream cin ("maze1.in");

    int a[201][76];
    int w,h;
    cin >> w >> h;

    int e = 0;
    deque<pi> waits;
    string s;

    getline(cin, s);
    for (int i=0;i<2*h+1;i++) {
        getline(cin, s);

        for (int j=0;j<2*w+1;j++) {
            a[i][j] = (s[j]==' '? w*h+1 : -1);
            
            if (s[j] == ' ')  {
                if (i==0)   waits.push_back(pi((i+1)*(2*w+1) + j, 1));
                if (i==2*h) waits.push_back(pi((i-1)*(2*w+1) + j, 1));
                if (j==0)   waits.push_back(pi(i*(2*w+1) + j+1, 1));
                if (j==2*w) waits.push_back(pi(i*(2*w+1) + j-1, 1));
            }    
        }
    }

    int ans=w*h;

    while(!waits.empty()) {
        pi x = waits.front();
        waits.pop_front();

        int i = x.first / (2*w+1);
        int j = x.first % (2*w+1);
        int t = x.second;

        a[i][j] = ans = t;
        cout << t << " " << i << " " << j << endl;

        for (int d=0;d<4;d++) {
            int i_ = i + 2*dirs[d][0];
            int j_ = j + 2*dirs[d][1];

            if (i_ > 0 && i_ < 2*h && j_ >  0 && j_ < 2*w) { // inside boundary
                if (a[i_][j_] > t+1 && a[i_ - dirs[d][0]][j_ - dirs[d][1]] > -1) 
                {  
                    a[i_][j_] = t+1;
                    waits.push_back(pi(i_ * (2*w+1) + j_, t+1));
                }
            }
        }
    }

    cout << ans << endl;
        

    return 0;
}