#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

bool theTruthIsOutThere(const pair<string,int> &a, const pair<string,int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main(void) {
    int cases, N, M, L, a, b;
    string input, name;

    cin >> cases;

    REPI (case_number, 1, cases) {
        cin >> N >> M >> L;
        cin.ignore(100, '\n');

        vector< pair<string, int> > result;

        while (L--) {
            getline (cin, input);

            name = "";
            int idx = 0;

            while (input[idx] != ':') {
                name += input[idx];
                idx++;
            }

            idx++;

            a = b = 0;

            while (input[idx] != ',') {
                a = a * 10 + (input[idx] - '0');
                idx++;
            }

            idx++;

            while (idx < input.size()) {
                b = b * 10 + (input[idx] - '0');
                idx++;
            }

            int current = N;
            int spent = 0;

            while (current / 2 >= M) {
                int diff = current - (current / 2);
                spent += min(diff * a, b);
                current /= 2;
            }

            if (current > M) {
                spent += a * (current - M);
            }

            result.push_back(make_pair(name, spent));
        }

        sort (result.begin(), result.end(), theTruthIsOutThere);

        cout << "Case " << case_number << endl;
        rep (i, result.size())
            cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
