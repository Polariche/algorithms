#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define ll long long

void test() {
    int X, Y, K;
    int m;
    
    int ansX, ansY;
    cin >> X >> Y >> K;
    m = min(X, Y);

    cout << m << " " << 0 << " ";
    cout << 0 << " " << m << "\n";

    cout << 0 << " " << 0 << " ";
    cout << m << " " << m << "\n";
}

int main () {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) test();
}