#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    int N;
    int s=0;
    cin >> N;

    for (int i=0;i<2*N;i++) {
        int x;
        cin >> x;
        s += x;
    }

    if (s >= N)
        s = N- (s-N);
    cout << s % 2 << " " << s << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}