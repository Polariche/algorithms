/*
ID: polaric2
TASK: pprime
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
#include <cmath>
#include <stdlib.h>

using namespace std;

typedef long long ll;

#define MAX 10000
#define count(x) (int(floor(log10((double)x)))+1)

vector<int> primes;

bool prime(int n) {
    for (int& p : primes) {
        if (n<=p)   break;
        if (n%p == 0) return 0;
        
    }
    
    return 1;
}

int main() {
    ofstream cout ("pprime.out");
    ifstream cin ("pprime.in");

    int a,b;
    cin >> a >> b;

    for (int i=2;i<=min(MAX+1,b);i++) {
        if (prime(i)) primes.push_back(i);
    }

    for (int m=count(a);m<=count(b);m++) {
        int n=m/2+m%2;
        int s=pow(10,n-1);
        int e=s*10;
        
        for (int i=s;i<e;i++) {
            int x=i;
            char p[m+1];
            int t;
            
            for (int i=0;i<n;i++) {
                p[n-i-1] = p[n+i+!(m%2)-1] = (x%10) + '0';
                x/=10;
            }
            p[m] = '\0';

            t = atoi(p);

            if (t > b || t < a) continue;
            if (prime(t)) cout << t << endl;
        }
    }

    return 0;
}