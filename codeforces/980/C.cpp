#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long

bool compare(pair<ll,ll> &a, pair<ll,ll> &b) {
    return a.first+a.second == b.first+b.second ? a.second < b.second : a.first+a.second < b.first+b.second;
}

void test() {
	int N;
    cin >> N;
    vector<pair<ll,ll>> arr;

    for (int i=0;i<N;i++) {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i=0;i<N;i++)
        cout << arr[i].first << " " << arr[i].second << " ";
    cout << "\n";
    return;
}

int main() {
	// your code goes here
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>> T;
	while (T--)	test();
	return 0;
}