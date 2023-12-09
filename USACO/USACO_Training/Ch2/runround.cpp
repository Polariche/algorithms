/*
ID: polaric2
TASK: runround
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
using namespace std;

typedef long long ll;

#define f first
#define s second

typedef pair<int,int> pi;


int main() {
    ofstream cout ("runround.out");
    ifstream cin ("runround.in");

    unsigned long long M;
    cin >> M;
    bool z = true;

    while (z) {
        M++;

        int N = int(log10(M)) + 1;
        int uniq[10]={0}; // uniqueness of digits & non-zero
        int touch[N]={0}; // touch a digit
        char c[10];
        int s  = 0;
        
        z = false;
        
        sprintf(c, "%llu", M);
        for (int i=0;i<N;i++) {
            int a = s%N;
            int b = c[a]-'0';
            
            if (uniq[b]) z = 1;
            uniq[b] = touch[a] = 1;

            s += b;
        }

        z |= s%N;

        if (uniq[0])    z = true;
    }
    

    cout << M << endl;

    return 0;
}