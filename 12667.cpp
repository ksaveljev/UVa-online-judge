#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

struct submission {
    int time;
    int team_id;
    char problem;
};

bool operator<(const submission& a, const submission& b) {
    return a.time < b.time;
}

int main(void) {
    int n, t, m;
    vector<submission> accepted;
    char P = 'A';

    cin >> n >> t >> m;

    int a, b;
    char c;
    string verdict;
    while (m--) {
        cin >> a >> b >> c >> verdict;

        if (c > P) {
            P = c;
        }

        if (verdict == "Yes") {
            submission tmp;
            tmp.time = a;
            tmp.team_id = b;
            tmp.problem = c;
            accepted.push_back(tmp);
        }
    }

    sort(accepted.begin(), accepted.end());

    for (char p = 'A'; p <= P; p++) {
        pair<int,int> result = {-1, -1};
        map<int,bool> solved;

        for (auto x: accepted) {
            if (x.problem == p) {
                if (solved[x.team_id]) continue;
                result = {x.time, x.team_id};
                solved[x.team_id] = true;
            }
        }

        if (result.first == -1) {
            cout << p << " " << "- -" << endl;
        } else {
            cout << p << " " << result.first << " " << result.second << endl;
        }
    }

    return 0;
}
