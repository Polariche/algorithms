#include <iostream>
using namespace std;

#define ll long long
ll test() {
	ll a,b;
	cin >> a >> b;
	
	ll s = 0;
	ll e = b;
	
	ll mx = 0;
	
	while (s <= e) {
		ll m = (s+e) / 2;
		if (a-m >= b - 2*m) {
			mx = max(mx, a-m);
			e = m-1;
		} else {
			s = m+1;
		}
	}
	
	return mx;
}

int main() {
	// your code goes here
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>> T;
	while (T--)	cout << test() << "\n";
	return 0;
}