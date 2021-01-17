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

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int k;
        string input;
        set<char> p[2][5], diff[5];

        cin >> k;

        for (int i = 0; i < 6; i++) {
            cin >> input;
            for (int j = 0; j < 5; j++) {
                p[0][j].insert(input[j]);
            }
        }
        for (int i = 0; i < 6; i++) {
            cin >> input;
            for (int j = 0; j < 5; j++) {
                p[1][j].insert(input[j]);
            }
        }

        for (int i = 0; i < 5; i++) {
            set_intersection(p[0][i].begin(), p[0][i].end(), p[1][i].begin(), p[1][i].end(), inserter(diff[i], diff[i].begin()));
        }

        vector<string> result;
        for (char a : diff[0]) {
            for (char b : diff[1]) {
                for (char c : diff[2]) {
                    for (char d : diff[3]) {
                        for (char e : diff[4]) {
                            result.push_back(string({a, b, c, d, e}));
                        }
                    }
                }
            }
        }

        sort(result.begin(), result.end());

        if (k > result.size()) {
            cout << "NO" << endl;
        } else {
            cout << result[k-1] << endl;
        }
    }

    return 0;
}
