/*
ID: polaric2
TASK: preface
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
using namespace std;

typedef long long ll;

#define f first
#define s second

typedef pair<int,int> pi;


int main() {
    ofstream cout ("preface.out");
    ifstream cin ("preface.in");

    //int an[10] = {0,1,2,3,1,0,1,2,3,1};
    //int bn[10] = {0,0,0,0,0,1,1,1,1,0};
    //int an1[10] = {0,0,0,0,0,0,0,0,0,1};

    int An[11] = { 0, 1, 3, 6, 7, 7, 8,10,13,14,14};
    int Bn[11] = { 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5};
    int An1[11]= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

    char ca[4] = {'I', 'X', 'C', 'M'};
    char cb[4] = {'V', 'L', 'D', ' '};

    int N;

    cin >> N;

    int n = int(log10(N)) + 1;

    int a[n+1] = {0};
    int b[n+1] = {0};
    int t = 1;

    // O(log N)
    for (int i=0;i<n+1;i++) {
        int x=N/t, y=(N%t)+1, z=x/10, w=x%10;
        
        // y : for lower digits
        // z : for upper digits
        // w : current digit

        // suppose we have N=367, and we're computing for i=1 (=second digit)
        // w0~w9   : t*(M[w]-M[w-1])
        // 0~99    : t*M[10]

        // 0~299   : z*t*M[10]              
        // 300~359 : t*M[w-1]               
        // 360~367 : y*(M[w]-M[w-1])        

        #define func(m, i, M) m[i] += z*t*M[10] + (w>0 ? t*M[w-1]+y*(M[w]-M[w-1]) : y*M[w]);

        func(a,i,An)
        func(b,i,Bn)
        func(a,i+1,An1)

        t *= 10;
    }

    for (int i=0;i<n+1;i++) {
        if (a[i]) cout << ca[i] << " " << a[i] << endl;
        if (b[i] && i<3) cout << cb[i] << " " << b[i] << endl;
    }
    
    return 0;
}