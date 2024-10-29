#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define ll long long

void test() {
    int N;
    cin >> N;
    vector<ll> arr(N);

    for (int i=0;i<N;i++)
        cin >> arr[i];

    if (N==1) {
        cout << 1 << "\n";
        
    } else if (N%2 == 0) {
        ll ans = 0;
        for (int i=1;i<N;i+=2)
            ans = max(ans, arr[i] - arr[i-1]);

        cout << ans << "\n";

    } else {
        ll trueans = 1987654321987654321;
        for (int i=0;i<N;i+=2) {
            // exclude i
            ll ans = 0;

            for (int j=1;j<N;j+=2) {
                if (i==j-1)
                    j++;
                ans = max(ans, arr[j] - arr[j-1]);
            }
            trueans = min(ans, trueans);
        }
        cout << trueans << "\n";
    }

    return;
}

int main () {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) test();
}