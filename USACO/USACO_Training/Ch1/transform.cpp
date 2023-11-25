/*
ID: polaric2
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define swap(x,y)

int rotation90(char a[], char b[], int N) {
    // #1: 90 degree rotation
    for (int i=0;i<N*N;i++) {
        int r=i/N, c=i%N;
        if (a[i] != b[c*N+(N-r-1)])
            return 0;
    }
    return 1;
}

int rotation180(char a[], char b[], int N) {
    // #2: 180 degree rotation
    for (int i=0;i<N*N;i++) {
        if (a[i] != b[N*N-i-1])
            return 0;
    }
    return 1;
}


int rotation270(char a[], char b[], int N) {
    // #3: 270 degree rotation
    for (int i=0;i<N*N;i++) {
        int r=i/N, c=i%N;
        if (a[i] != b[(N-c-1)*N+r])
            return 0;
    }
    return 1;
}


int identical(char a[], char b[], int N) {
    for (int i=0;i<N*N;i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

// different from others due to #5
void reflect(char b[], int N) {
    for (int i=0;i<N*(N/2);i++) {
        int r=i%N, c=i/N;
        int tmp = b[r*N+c];
        b[r*N+c] = b[r*N+N-c-1];
        b[r*N+N-c-1] = tmp;
    }
}

int main() {
    ofstream cout ("transform.out");
    ifstream cin ("transform.in");
    
    int N;
    cin >> N;

    char a[N*N], b[N*N];
    int ans=7;

    for (int i=0;i<N*N;i++) cin >> a[i];
    for (int i=0;i<N*N;i++) cin >> b[i];

    int i;
    for (i=0;i<2;i++) {
        if (rotation90(a,b,N))    { ans = max(1, i*5); break; }
        if (rotation180(a,b,N))   { ans = max(2, i*5); break; }
        if (rotation270(a,b,N))   { ans = max(3, i*5); break; }

        if (i==0) { reflect(b, N); }

        if (identical(a,b,N))   { ans = i==0? 4 : 6; break; }
    }

    cout << ans << endl;

    return 0;
}