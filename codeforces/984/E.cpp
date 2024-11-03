#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    int N, K, Q;
    cin >> N >> K >> Q;

     vector<vector<ll>> arr(K, vector<ll>(N, 0));

    for (int i=0;i<N;i++) {
        for (int j=0;j<K;j++) {
            cin >> arr[j][i];
            if (i>0)
                arr[j][i] |= arr[j][i-1];
        }
    }

    for (int i=0;i<Q;i++) {
        int left = 0;
        int right = K;

        int conditions;
        cin >> conditions;

        for (int j=0;j<conditions;j++) {
            int a, b;
            char query;
            cin >> a >> query >> b;

            if (query == '>')
                left = max(left, (int) (upper_bound(arr[a-1].begin(), arr[a-1].end(), b) - arr[a-1].begin()));
            else
                right = min(right, (int) (lower_bound(arr[a-1].begin(), arr[a-1].end(), b) - arr[a-1].begin()));
        }

        if (left >= right)
            cout << -1 << "\n";
        else
            cout << left + 1 << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    test();
}