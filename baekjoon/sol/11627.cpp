#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int L,W;
int godzilla;

bool world[1001][1001];
int gz_visit[1001][1001];
int mc_visit[1001][1001];

vector<int> destroyed_cnt;
vector<int> gz_walk;
vector<int> mechs;

// North, East, South, West
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init() {
	memset(world, 0, sizeof(world));
	memset(gz_visit, 0, sizeof(gz_visit));
	memset(mc_visit, 0, sizeof(mc_visit));

	destroyed_cnt.clear();
	gz_walk.clear();
    mechs.clear();
}

void input() {
	cin >> L >> W;
	for (int i=0;i<W;i++) {
		string s;
		cin >> s;
		for (int j=0;j<L;j++) {
			if (s[j] == 'R') {
				world[i][j] = 1;
			} else if (s[j] == 'G') {
				godzilla = i*L + j;
			} else if (s[j] == 'M') {
				mechs.push_back(i*L + j);
			}
		}
	}
}

void compute_godzilla_path() {
	
	int killcnt = 0;
	
	bool found_next = 1;
	int t = 1;
	gz_visit[godzilla/L][godzilla%L] = t;
	
	destroyed_cnt.push_back(0);	// 0
	destroyed_cnt.push_back(0);	// 1
	
	gz_walk.push_back(-1);
	gz_walk.push_back(godzilla);
	
	while (found_next) {
		int x = godzilla / L;
		int y = godzilla % L;
		found_next = 0;
		
		int new_pos;
		
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= W || ny >= L)
				continue;
			if (gz_visit[nx][ny])
				continue;
				
			if (world[nx][ny]) {
				new_pos = nx*L + ny;
				found_next = 1;
				killcnt++;
				break;
			} else if (!found_next) {
				new_pos = nx*L + ny;
				found_next = 1;
			}
		}
		
		if (found_next) {
			godzilla = new_pos;
			gz_visit[new_pos/L][new_pos%L] = t+1;
		}
		destroyed_cnt.push_back(killcnt);
		gz_walk.push_back(godzilla);
        t++;
	}
}

void display_godzilla_path() {
	for(int i=0;i<W;i++) {
		for (int j=0;j<L;j++)
			cout << gz_visit[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void display_mech_path() {
	for(int i=0;i<W;i++) {
		for (int j=0;j<L;j++)
			cout << mc_visit[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}


void display_destroy_time() {
	for(int i=0;i<W;i++) {
		for (int j=0;j<L;j++)
			cout << (world[i][j] ? gz_visit[i][j] : 0)  << " ";
		cout << "\n";
	}
	cout << "\n";
}

void display_timeline() {
	for (int a : destroyed_cnt)
		cout << a << " ";
	cout << "\n";
}

void compute_mech_path() {
	priority_queue<pair<int,int>> pq;
	
	for (int m : mechs) {
		pq.push({-1,m});
		mc_visit[m/L][m%L] = 1;
	}
	
	while (!pq.empty()) {
		auto [t, a] = pq.top(); pq.pop();
		int x = a/L;
		int y = a%L;

        //cout << -t << " " << x << " " << y << "\n";
		
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <0 ||ny <0 || nx>=W || ny >= L)
				continue;
			if (mc_visit[nx][ny] && mc_visit[nx][ny] <= mc_visit[x][y]+1)
				continue;

			if (world[nx][ny]) {
                if (gz_visit[nx][ny]) {
                    mc_visit[nx][ny] = max(gz_visit[nx][ny], mc_visit[x][y]+1);
				    pq.push({-mc_visit[nx][ny], nx*L + ny});
                }
			} else {
				mc_visit[nx][ny] = mc_visit[x][y]+1;
				pq.push({-mc_visit[nx][ny], nx*L + ny});
			}	
			
		}
	}
}

int find_intersection() {
	for (int i=2;i<gz_walk.size();i++) {
		int a = gz_walk[i];
		int x = a/L;
		int y = a%L;
		
		for (int j=0;j<4;j++) {
			int nx = x;
			int ny = y;
			while (!(nx < 0 || ny < 0 || nx >= W || ny >= L)) {
				
				if (world[nx][ny] && (!gz_visit[nx][ny] || gz_visit[nx][ny] > i))
					break;
				
				if (mc_visit[nx][ny] <= i && mc_visit[nx][ny]) {
                    //cout << nx << " " << ny << " " << i << "\n";
					return i;
                }
					
				nx += dx[j];
				ny += dy[j];
			}
		}
	}
	return gz_walk.size()-1;
}

void test() {
	init();
	input();
	compute_godzilla_path();
	compute_mech_path();

	cout << destroyed_cnt[find_intersection()] << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	while (T--)	test();
	
	return 0;
}