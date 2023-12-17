/*
ID: polaric2
TASK: prefix
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pi;

#define MAX 200000
#define ctoi(A) (A=='\0'? 26 : (A-'A'))

int dp[MAX];

typedef struct node {
    node* next[27] ={0};
    node* prev=0;
} Node;

bool exist(Node* n, int i) {
    return (n->next[i])!=0;
}

Node* append(Node* n, int i) {
    if (!exist(n, i)) {
        Node* m = new Node();
        m->prev = n;
        n->next[i] = m;
    }
        
    return n->next[i];
}

int check(char* s, int start, Node* root) {
    Node* n = root;
    int ans = 0;

    if (dp[start] >= 0) return dp[start];
    
    for (int i=start;i<MAX&&s[i]!='\0';i++) {
        int t = ctoi(s[i]);
        if (exist(n, t)) {
            n = n->next[t];
            if (exist(n, ctoi('\0'))) {
                ans = max(ans, i - start + 1 + check(s, i+1, root));
            }
        } else
            break;
    }

    dp[start] = ans;
    return ans;
}


int main() {
    ofstream cout ("prefix.out");
    ifstream cin ("prefix.in");

    int N;

    Node * root = new Node();
    char c[MAX];
    int i;

    for (N=0;N<=201;N++) {
        string s;
        cin >> s;  

        if (s[0] == '.')
            break;

        Node* n = root;
        for (auto &a : s) {
            n = append(n, ctoi(a));
        }
        n = append(n, ctoi('\0'));
    }

    Node* n = root;

    for (i=0;i<MAX;i++) {
        cin >> c[i];

        dp[i] = -1;

        if (c[i] == '\n') {
            i--; continue;
        }
        if (c[i] == '\0')
            break;
    }

    for (;i>=0;i--)
        check(c, i, root);
    
    cout << check(c, 0, root) << endl;
    
    return 0;
}