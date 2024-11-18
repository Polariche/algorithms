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
    cin >> N;
    if (N <= 4) {
        cout << "-1\n";
        return;
    }

    else {
        for (int i=N;i>=1;i-=2) {
            if (i == 4 + N%2)
                continue;
            cout << i << " ";
        }
        cout << 4 + N%2 << " " << 4 + !(N%2) << " ";
        for (int i=1+(N%2);i<=N-1+(N%2);i+=2) {
            if (i == 4 + !(N%2))
                continue;
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}