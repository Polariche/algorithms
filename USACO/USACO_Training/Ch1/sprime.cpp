/*
ID: polaric2
TASK: sprime
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

int N;
vector<int> primes;

bool prime(int n) {
    for (int& p : primes) {
        if (n<=p)   break;
        if (n%p == 0) return 0;
    }
    return 1;
}

void solve(int x, ofstream * cout) {
    if (!prime(x)) return;
    if (count(x) == N) {
        *cout << x << endl;
        return;
    }

    x*=10;

    for (int i=1;i<10;i+=2)
        solve(x+i, cout);
}

int main() {
    ofstream cout ("sprime.out");
    ifstream cin ("sprime.in");

    cin >> N;
    
    int t = pow(10,N/2+N%2);
    int seeds[4] = {2,3,5,7};

    for (int i=2;i<min(t,MAX)+1;i++) {
        if (prime(i)) primes.push_back(i);
    }

    for (int &s : seeds) {
        solve(s, &cout);
    }

    return 0;
}