#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

enum class Type {
    None,
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
};

// 0 for white, 1 for black
bool cur_side;
int myking;
char raw_map[8][8];

Type chess[8][8];

bool side[8][8];

set<int> threat_map[2][8][8];
vector<int> mypawns;            // we're all pawns on the chessboard

// [0, 4): horizontal / vertical (for queens and rooks)
// [4, 8): diagonal (for queens and bishops)
int dx[8] = {-1, 1, 0, 0, 
            -1, 1, 1, -1};

int dy[8] = {0, 0, -1, 1, 
            -1, 1, -1, 1};

// for knights
int dx_n[8] = {-2,-2, -1, -1, 1, 1, 2, 2};
int dy_n[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

#define MARK_AND_CAPTURE(s, i, j) if (diff > 0)\
                                    threat_map[!s][i][j].insert(x*8+y);\
                                  else\
                                    threat_map[!s][i][j].erase(x*8+y);

#define THREAT_BY_LINE(dirs, dire) \
    for (int k=dirs;k<dire;k++) {\
        int i = x + dx[k];\
        int j = y + dy[k];\
        while (!(i < 0 || j < 0 || i >= 8 || j >= 8)) {\
            MARK_AND_CAPTURE(s, i, j);\
            if (chess[i][j] != Type::None)\
                break;\
            i += dx[k];\
            j += dy[k];\
        }\
    }

void threat_by_king(int x, int y, int diff) {
    bool s = side[x][y];

    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) {
            MARK_AND_CAPTURE(s, i, j);
        }
    }
}

void threat_by_queen(int x, int y, int diff) {
    bool s = side[x][y];
    MARK_AND_CAPTURE(s, x, y)

    THREAT_BY_LINE(0, 8);

}

void threat_by_rook(int x, int y, int diff) {
    bool s = side[x][y];
    MARK_AND_CAPTURE(s, x, y)

    THREAT_BY_LINE(0, 4);
}
void threat_by_bishop(int x, int y, int diff) {
    bool s = side[x][y];
    MARK_AND_CAPTURE(s, x, y)

    THREAT_BY_LINE(4, 8);
}
void threat_by_knight(int x, int y, int diff) {
    bool s = side[x][y];
    MARK_AND_CAPTURE(s, x, y)

    for (int k=0;k<8;k++) {
        int i = x + dx[k];
        int j = y + dy[k];
        MARK_AND_CAPTURE(s, i, j);
    }
}

void init() {
    memset(chess, 0, sizeof(chess));
    //memset(threat_map, 0, sizeof(threat_map));
    memset(side, 0, sizeof(side));

    for (int k=0;k<2;k++) {
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                threat_map[k][i][j].clear();
            }
        }
    }

    mypawns.clear();
}

void input() {
    char side_c;
    cin >> side_c;
    cur_side = (side_c == 'B');

    for (int i=0;i<8;i++) {
        string s;
        cin >> s;

        for (int j=0;j<8;j++) {
            raw_map[i][j] = s[j];

            switch(s[j]) {
                case '.':   chess[i][j] = Type::None; break;
                case 'k':
                case 'K':   chess[i][j] = Type::King; break;
                case 'q':
                case 'Q':   chess[i][j] = Type::Queen; break;
                case 'r':
                case 'R':   chess[i][j] = Type::Rook; break;
                case 'b':
                case 'B':   chess[i][j] = Type::Bishop; break;
                case 'n':
                case 'N':   chess[i][j] = Type::Knight; break;
            }

            if (chess[i][j] != Type::None)
                side[i][j] = (s[j] <= 'Z');

            if (chess[i][j] == Type::King && side[i][j] == cur_side)
                myking = i*8+j;
            
            if (side[i][j] == cur_side)
                mypawns.push_back(i*8+j);
        }
    }
    return;
}

bool threat_by(int i, int j, int diff) {
    if (chess[i][j] == Type::None)
        return 0;

    switch(chess[i][j]) {
        case Type::King:
            threat_by_king(i, j, diff); break;
        case Type::Queen: 
            threat_by_queen(i, j, diff); break;
        case Type::Rook: 
            threat_by_rook(i, j, diff); break;
        case Type::Bishop: 
            threat_by_bishop(i, j, diff); break;
        case Type::Knight: 
            threat_by_knight(i, j, diff); break;
        default: break;
    }

    return 1;
}

void create_threat() {
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            threat_by(i, j, 1);
        }
    }
}

void display_threat(bool s) {
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            cout << threat_map[s][i][j].size();
        }
        cout << "\n";
    }
}

bool try_evade() {
    // try to move a vacant, peaceful space

    int x = myking / 8;
    int y = myking % 8;

    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) {
            if (i==x && j==y)
                continue;

            if (threat_map[cur_side][i][j].size() == 0)
                return 1;
        }
    }
    return 0;
}

#define MYKING_THREATS threat_map[cur_side][myking/8][myking%8]

bool try_violence() {
    // peace is not always an option...

    if (MYKING_THREATS.size() > 1)
        return 0;

    int t = *(MYKING_THREATS.begin());
    

    return 0;
}

bool try_block() {
    if (MYKING_THREATS.size() > 1)
        return 0;

    int t = *(MYKING_THREATS.begin());


    return 0;
}

void test() {
    init();
    input();
    create_threat();

    cout << "\n";
    display_threat(cur_side);

    if (!cur_side)
        cout << "WHITE IS ";
    else
        cout << "BLACK IS ";

    if (MYKING_THREATS.size() == 0)
        cout << "SAFE\n";

    else if (try_evade() || try_violence() || try_block())
        cout << "CHECKED\n";

    else
        cout << "CHECKMATED\n";
    

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	while (T--)	test();
	
	return 0;
}