/*
ID: polaric2
TASK: namenum
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

map <char, int> MAP = {{'A',2},{'B',2},{'C',2},
                        {'D',3},{'E',3},{'F',3},
                        {'G',4},{'H',4},{'I',4},
                        {'J',5},{'K',5},{'L',5},
                        {'M',6},{'N',6},{'O',6},
                        {'P',7},{'R',7},{'S',7},
                        {'T',8},{'U',8},{'V',8},
                        {'W',9},{'X',9},{'Y',9},
                        {'Q',10},{'Z',10}};

typedef struct node{
    node* next;
    int start, end;
}node;

int main() {
    ofstream cout ("namenum.out");
    ifstream cin ("namenum.in");
    ifstream din ("dict.txt");
    
    // Be extra careful about data types!!
    // int : -2,147,483,648 ~ 2,147,483,647 -> only 10 digits
    ll number;

    int i, n_length=0, cnt=0;
    vector <int> n;

    node* root = new node();
    
    cin >> number;

    for (i=0;i<12;i++) {
        if (number) {
            n.push_back(number % 10);
            number /= 10;
            n_length++;
        }
        else break;
    }

    i=0;
    while (!din.eof()) {
        node* current = root;
        int j = 0;
        string s;
        din >> s;

        if (s.length() != n_length) continue;

        for (char& c : s) {
            int t = MAP[c];
            if (t != n[n_length-j-1])  break;

            if (!current->next) {
                node* n = new node();
                n->start = i;
                current->next = n;
            }

            current = current->next;
            current->end = i;

            if (j == n_length-1) {
                cout << s << endl;
                cnt++;
                break;
            }
            j++;
        }
        i++;
    }

    if (!cnt)
        cout << "NONE" << endl;

    return 0;
}