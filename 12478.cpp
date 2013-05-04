#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

char grid[9][9] = {
    {'O','B','I','D','A','I','B','K','R'},
    {'R','K','A','U','L','H','I','S','P'},
    {'S','A','D','I','Y','A','N','N','O'},
    {'H','E','I','S','A','W','H','I','A'},
    {'I','R','A','K','I','B','U','L','S'},
    {'M','F','B','I','N','T','R','N','O'},
    {'U','T','O','Y','Z','I','F','A','H'},
    {'L','E','B','S','Y','N','U','N','E'},
    {'E','M','O','T','I','O','N','A','L'}
};

map<string,int> all_names;

string names[8] = {"RAKIBUL","ANINDYA","MOSHIUR","SHIPLU","KABIR","SUNNY","OBAIDA","WASI"};

void build_horizontal_name(int row, int col, int len) {
    string name = "";

    rep (i, len) {
        name += grid[row][col + i];
    }

    sort(name.begin(), name.end());

    if (all_names.find(name) == all_names.end())
        all_names[name] = 1;
    else
        all_names[name] = all_names[name] + 1;
}

void build_vertical_name(int row, int col, int len) {
    string name = "";

    rep (i, len) {
        name += grid[row + i][col];
    }

    sort(name.begin(), name.end());

    if (all_names.find(name) == all_names.end())
        all_names[name] = 1;
    else
        all_names[name] = all_names[name] + 1;
}

bool theTruthIsOutThere(const string &a, const string &b) {
    if (a.size() > b.size())
        return false;
    else
        return true;
}

int main(void) {
    sort(names, names+8, theTruthIsOutThere);

    int min_length = names[0].size();
    int max_length = names[7].size();

    REP (len, min_length, max_length+1) {
        rep (i, 9) {
            rep (j, 9 - len + 1) {
                build_horizontal_name(i, j, len);
            }
        }

        rep (i, 9 - len + 1) {
            rep (j, 9) {
                build_vertical_name(i, j, len);
            }
        }
    }

    rep (i, 8) {
        string n = string(names[i]);
        sort(n.begin(), n.end());

        if (all_names[n] == 2)
            cout << names[i] << endl;
    }

    return 0;
}
