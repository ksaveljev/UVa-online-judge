#include <iostream>
#include <vector>
#include <algorithm>
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

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve(int M, vector< pair<int,int> > &lines, vector< pair<int,int> > &result) {
    int end = 0;
    int index = 0;
    bool first = true;
    pair<int,int> tmp = make_pair(-1, -1);
    
    while (index < sz(lines)) {
        if (lines[index].first <= end) {
            if (first) {
                tmp = lines[index];
                first = false;
            } else if (lines[index].second > tmp.second) {
                tmp = lines[index];
            }
            index++;
        } else {
            if (first)
                break;
            result.push_back(tmp);
            end = tmp.second;
            first = true;
            if (end >= M) break;
        }
    }

    if (!first) result.push_back(tmp);
}

int main(void) {
    int cases, M;
    pair<int,int> tmp;

    cin >> cases;

    while (cases--) {
        cin >> M;
        vector< pair<int,int> > lines;
        vector< pair<int,int> > result;

        while (cin >> tmp.first >> tmp.second) {
            if (tmp.second < 0) continue;
            if (tmp.first == 0 && tmp.second == 0) break;
            lines.push_back(tmp);
        }

        sort (lines.begin(), lines.end(), theTruthIsOutThere);

        if (lines[0].first > 0) {
            cout << 0 << endl;
        } else {
            solve(M, lines, result);
            if (result.empty() || result[result.size()-1].second < M)
                cout << 0 << endl;
            else {
                cout << sz(result) << endl;
                rep (i, sz(result))
                    cout << result[i].first << " " << result[i].second << endl;
            }
        }

        if (cases) cout << endl;
    }

    return 0;
}
