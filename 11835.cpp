#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;
}

int main(void) {
    int g, p, tmp, s, k;

    while (cin >> g >> p) {
        if (g == 0 && p == 0)
            break;

        vector< vector< pair<int,int> > > results;

        while (g--) {
            vector< pair<int,int> > result;

            rep (i, p) {
                cin >> tmp;
                result.push_back(make_pair(i+1, tmp));
            }

            sort (result.begin(), result.end(), theTruthIsOutThere);

            results.push_back(result);
        }

        cin >> s;

        while (s--) {
            cin >> k;

            int points[k];

            rep (i, k) {
                cin >> points[i];
            }

            int score[p+1];

            rep (i, p+1)
                score[i] = 0;

            int best = 0;

            rep (i, results.size()) {
                rep (j, min(int(results[i].size()), k)) {
                    score[results[i][j].first] += points[j];

                    if (score[results[i][j].first] > best)
                        best = score[results[i][j].first];
                }
            }

            bool first = true;

            rep (i, p+1) {
                if (score[i] == best) {
                    if (!first)
                        cout << " ";

                    cout << i;
                    first = false;
                }
            }

            cout << endl;
        }
    }

    return 0;
}
