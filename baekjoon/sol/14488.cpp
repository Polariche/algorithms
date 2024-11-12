#include <iostream>
#include <vector>
using namespace std;
#define ll long long


ll cross2 (ll x1, ll y1, ll x2, ll y2) {
    return x1*y2-y1*x2;
}

void cross3 (ll x1, ll y1, ll z1,
             ll x2, ll y2, ll z2,
             ll *x, ll *y, ll *z) {
				
	*x = cross2(y1, z1, z1, z2); 
	*y = cross2(z1, x1, z2, x2); 
	*z = cross2(x1, y1, x2, y2); 
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    float T;

    cin >> N >> T;

    vector<ll> pos(N);
    vector<ll> vel(N);
    vector<bool> meet(N);

    for (int i=0;i<N;i++)
        cin >> pos[i];
    for (int i=0;i<N;i++)
        cin >> vel[i];

    
    for (int i=0;i<N;i++) {
        if (meet[i])
            continue;

        ll x, y, z;
        for (int j=i+1;j<N;j++) {
            cross3(vel[i], -1, -pos[i], 
                   vel[j], -1, -pos[j], 
                   &x, &y, &z);
            cout << i << " " << j << " " << x << " " << y << " " << z <<"\n";

            if (z) {
                if (x <= T * -z && x * -z >= 0) {
                    meet[i] = meet[j] = 1;
                }
            } else if (x == y) {
                meet[i] = meet[j] = 1;
            }

        }
    }

    for (int i=0;i<N;i++) {
        cout << meet[i] << " ";
        if (!meet[i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}