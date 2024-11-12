#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define COLOR_WHITE     0     // up
#define COLOR_YELLOW    3     // down
#define COLOR_RED       1     // front
#define COLOR_ORANGE    4     // back
#define COLOR_GREEN     5     // left
#define COLOR_BLUE      2     // right

int cube[6][3][3];

vector<pair<int*, int>> rings[6] = {{{&cube[1][0][0], 1}, {&cube[2][0][0], 1}, {&cube[4][0][0], 1}, {&cube[5][0][0], 1}},
									{{&cube[5][0][2], 3}, {&cube[3][0][2], 3}, {&cube[2][2][0], -3}, {&cube[0][2][2], -1}},
									{{&cube[0][0][2], 3}, {&cube[1][0][2], 3},  {&cube[3][2][2], -1}, {&cube[4][2][0], -3}},
									
									{{&cube[5][2][2], -1}, {&cube[4][2][2], -1}, {&cube[2][2][2], -1}, {&cube[1][2][2], -1}},
									{{&cube[0][0][0], 1},  {&cube[2][0][2], 3}, {&cube[3][2][0], -3}, {&cube[5][2][0], -3}},
									{{&cube[4][0][2], 3}, {&cube[3][0][0], 1}, {&cube[1][2][0], -3}, {&cube[0][2][0], -3}}};

void init_cube() {
    for (int i=0;i<6;i++) {
        for (int j=0;j<9;j++)
            cube[i][j/3][j%3] = i;
    }
}

void rotate_face(int face, bool ccw) {
    // 0 1 2
    // 3 4 5
    // 6 7 8

    // CCW:
    // 2 5 8
    // 1 4 7
    // 0 3 6

    // CW:
    // 6 3 0
    // 7 4 1
    // 8 5 2

    int temp[3][3];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++)
            temp[i][j] = ccw ? cube[face][j][2-i] : cube[face][2-j][i];
    }
    
    memcpy(cube[face], temp, 9*sizeof(int));
}

void rotate_ring(int face, bool ccw) {
	for (int k=0;k<3;k++) {
		int tmp = *(rings[face][0].first + k*rings[face][0].second);
		int t = 0;
		
		for (int i=0;i<4;i++) {
			int t2 = (t + 4 + (ccw ? -1:1)) % 4;
			
			int* pt = rings[face][t].first + k*rings[face][t].second;
			int* pt2 = rings[face][t2].first + k*rings[face][t2].second;
				
			if (t2 == 0)
				*pt = tmp;
			else
				*pt = *pt2;
				
			t = t2;
		}	
	}
	
}

void test() {
    int N;
    cin >> N;

    init_cube();

    for (int i=0;i<N;i++) {
        char cface, cdir;
        int face; 
        bool ccw;
        
        cin >> cface >> cdir;
        
        switch(cface) {
        	case 'U': face=0;break;
        	case 'D': face=3;break;
        	case 'F': face=1;break;
        	case 'B': face=4;break;
        	case 'L': face=5;break;
        	case 'R': face=2;break;
        }
        switch(cdir) {
        	case '-': ccw=1;break;
        	case '+': ccw=0;break;
        }
        
        rotate_face(face, ccw);
        rotate_ring(face, ccw);
    }
    
    for (int i=0;i<3;i++) {
    	for (int j=0;j<3;j++) {
    		switch(cube[0][i][j])	{
    			case COLOR_WHITE: cout << 'w'; break;
    			case COLOR_GREEN: cout << 'g'; break;
    			case COLOR_RED: cout << 'r'; break;
    			case COLOR_ORANGE: cout << 'o'; break;
    			case COLOR_BLUE: cout << 'b'; break;
    			case COLOR_YELLOW: cout << 'y'; break;
    		}
    	}
    	cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) test();
}