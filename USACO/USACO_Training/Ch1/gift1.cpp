/*
ID: polaric2
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int N;
map<string, int> money;
vector<string> people;

void give(string giver, int amount, int M, ifstream fin) {
    
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    string best;
    int bestmoney=0;

    fin >> N;

    for (int i=0;i<N;i++) {
        string f;
        fin >> f;

        money[f] = 0;
        people.push_back(f);
    }

    while (!fin.eof()) {
        string giver;
        int amount, M, each;
        fin >> giver >> amount >> M;
        
        if (!M)
            continue;
        
        each = amount/M;
        amount -= amount % M;
        money[giver] -= amount;

        for (int i=0;i<M;i++) {
            string f;
            fin >> f;
            money[f] += each;
        }
    }

    for (auto& k: people) {
        fout << k << " " << money[k] << endl;
    }
    
    return 0;
}