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

    vector<ll> arr(N);
    int ans = N;

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i=0;i<N-2;i++) {
        int t = lower_bound(arr.begin(), arr.end(), arr[i]+arr[i+1]) - arr.begin();
        //cout << i << " " << " " << i << " " << N-t << " " << "\n";
        ans = min(ans, i+N-t);
    }

    cout << ans << "\n";

    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}