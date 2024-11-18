#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long


void test() {
    int K;
    cin >> K;
    vector<int> arr(K);
    vector<int> exist(K+1);
    for (int i=0;i<K;i++) {
        cin >> arr[i];
        exist[arr[i]]++;
    }

    for (int i=0;i<K;i++) {
        if ((K-2)%arr[i] == 0 && exist[(K-2)/arr[i]]) {
            if ((K-2)/arr[i] == arr[i] && exist[(K-2)/arr[i]] < 2)
                continue;
            cout << arr[i] << " " << (K-2)/arr[i] << "\n";
            return;
        }
    }

    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}