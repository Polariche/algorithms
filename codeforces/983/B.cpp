#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    int N, K;
    cin >> N >> K;

    if (N==1) {
        cout << 1 << "\n" << 1 << "\n";
        return;
    }
    if (!((K-1)%2 == (N-K)%2 && (K-1)>0 && (N-K)>0)) {
        cout << -1 << "\n";
        return;
    }
    int left = K-1;
    int right = N-K;

    if (left%2 == 1) {
        cout << 3 << "\n";
        cout << 1 << " " << K << " " << K+1 << "\n";
    } else if (left%2 == 0 && N>=5) {
        cout << 5 << "\n";
        cout << 1 << " " << left << " " << K << " " << K+1 << " " << N << "\n";
    } else {
        cout << -1 << "\n";
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}