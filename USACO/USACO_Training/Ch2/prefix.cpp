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
#define ctoi(A) (A=='\0'? 28 : (A-'A'))

typedef struct node {
    node* next[30] ={0};
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


int main() {
    ofstream cout ("prefix.out");
    ifstream cin ("prefix.in");

    vector<string> raw;
    int N;

    Node * root = new Node();

    char c[MAX];
    char* pt = c;

    for (N=0;N<=201;N++) {
        string s;
        cin >> s;  

        if (s[0] == '.')
            break;

        raw.push_back(s);
    }

    for (auto &s : raw) {
        Node* n = root;

        for (auto &a : s) {
            n = append(n, ctoi(a));
        }
        n = append(n, ctoi('\0'));
    }

    Node* n = root;
    int cnt = 0;
    int sum = 0;
    deque<int> ends;
    ends.push_front(0);

    for (int i=0;i<MAX;i++) {
        cin >> *pt;
        int t = ctoi(*pt);

        if (*pt == '\n') {
            pt--; i--; continue;
        }

        if (*(pt-1) == '\0' && i>0)
            break;

        int k = 0;
        while (!ends.empty()) {
            int end = ends.front();
            int j;
            ends.pop_front();

            if (k) {
                n = root;
                for(j=end+1;j<i;j++) {
                    if (exist(n,ctoi(c[j]))) {
                        n=n->next[ctoi(c[j])];
                        if(exist(n, ctoi('\0')))
                            ends.push_back(j);
                    } else break;
                }
                if (j<i)
                    continue;
                else
                    sum = end+1;
            }

            if (exist(n, t) && *pt != '\0') {
                n = n->next[ctoi(c[i])];
                if(exist(n, ctoi('\0')))
                    ends.push_back(i);

                ends.push_front(i);
                break;
            }

            k++;
        }
            
        pt++;
    }

    cout << sum << endl;
    
    return 0;
}