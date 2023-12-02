/*
ID: polaric2
TASK: numtri
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

typedef long long ll;


int main() {
    ofstream cout ("numtri.out");
    ifstream cin ("numtri.in");

    int R;
    cin >> R;

    int t[R+1][R+1] = {0};
    int s[R+1][R+1] = {0};
    int m=0;

    memset(s, -1, (R+1)*(R+1)*sizeof(int));
    s[0][0] = s[0][1] = 0;

    for(int i=1;i<=R;i++) {
        for (int j=1;j<=i;j++) 
            cin >> t[i][j];
    }

    for(int i=1;i<=R;i++) {
        for (int j=1;j<=i;j++) {
            s[i][j] = max(s[i-1][j-1], s[i-1][j]) + t[i][j];
        }
    }

    for(int j=1;j<=R;j++) {
        m = max(m, s[R][j]);
    }

    cout << m << endl;

    return 0;
}