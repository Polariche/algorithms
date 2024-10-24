#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    int N;
    cin >> N;
    vector<ll> arr(N+1);
    vector<ll> sum(N+1);

    map<ll, vector<int>> sum_to_idx;
    map<ll, int> sum_to_idx_cur_ptr;
    vector<ll> cnt(N+1);

    for (int i=1;i<=N;i++)
        cin >> arr[i];
        
    for (int i=0;i<=N;i++) {
        ll s;
        if (i>0)
            s = sum[i] = sum[i-1] + arr[i];
        else
            s = 0;
        if (sum_to_idx.find(s) == sum_to_idx.end()) {
            sum_to_idx[s] = vector<int>();
            sum_to_idx_cur_ptr[s] = 0;
        }
        sum_to_idx[s].push_back(i);
    }

    for (int i=0;i<=N;i++) {
        ll s = sum[i];
        ll c = i>0 ? cnt[i-1] : 0;
        
        if (i && !arr[i]) {
            c = c+1;
        } else if (sum_to_idx_cur_ptr[s] > 0) {
            int j = sum_to_idx_cur_ptr[s]-1;
            int left = sum_to_idx[s][j];
            c = max(c, cnt[max(0, left)] + 1);
        }
        cnt[i] = c;
        
        sum_to_idx_cur_ptr[s]++;
    }

    cout << cnt[N] << "\n";

    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}