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
    for (int i=0;i<N;i++)
        cin >> arr[i];
    
    for (int i=1;i<N;i++) {
        if (abs(arr[i] - arr[i-1]) != 5 && abs(arr[i] - arr[i-1]) != 7) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}