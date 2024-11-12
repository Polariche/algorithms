#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;

    vector<pair<ll, ll>> arr(N);

    for (int i=0;i<N;i++)
        cin >> arr[i].first >> arr[i].second;
    
    int s = 0;
    ll mx;
    ll ans = 0;
    for (int e=0;e<N;e++) {
        if (e>0 && arr[e].first > mx) {
            ans += mx - arr[s].first;
            s = e;
        }
        
        if (s == e || arr[e].second > mx)
            mx = arr[e].second;
        
    }
    ans += mx - arr[s].first;
    cout << ans;
}