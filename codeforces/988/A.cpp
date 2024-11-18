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
    vector<int> arr(N);
    int ans = 0;
    vector<bool> checked(N);
    for (int i=0;i<N;i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());


    int s=0;
    for (int e=1;e<N;e++) {
        if (checked[e])
            continue;
            
        while (arr[s] < arr[e] || checked[s])
            s++;

        if (!(s==e) && arr[s] == arr[e]) {
            ans++;
            s++;
            checked[s] = checked[e] = 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}