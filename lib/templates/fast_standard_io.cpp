#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	cin >> M >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		ans = (ans + x) % MOD;
		if (M == 1) { cout << ans << "\n"; }
	}
	if (M == 0) { cout << ans << "\n"; }
}