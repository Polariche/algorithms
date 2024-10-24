#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> arr(N, vector<int>(N, 0));

    for (int i=0;i<N;i++) {
        string s;
        cin >> s;
        for (int j=0;j<N;j++) {
            arr[i][j] = s[j]-'0';
        }
    }

    for (int i=0;i<N;i+=K) {
        for (int j=0;j<N;j+=K)
            cout << arr[i][j];
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}