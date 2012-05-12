#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef struct _chain {
    int a, b, c;
    int hash() {
        return 1000000 * a + 1000 * b + c;
    }
} chain;

int relations[101][101];

bool theTruthIsOutThere (const chain &a, const chain &b) {
    if (a.a == b.a) {
        if (a.b == b.b) {
            return a.c < b.c;
        }

        return a.b < b.b;
    }

    return a.a < b.a;
}

int main(void) {
    int n;
    chain tmp;

    while (cin >> n) {
        rep (i, n)
            rep (j, n)
                cin >> relations[i][j];

        map<int,bool> visited;
        vector<chain> chains;

        rep (i, n) {
            rep (j, n) {
                if (i == j)
                    continue;

                if (!relations[i][j])
                    continue;

                rep (k, n) {
                    if (i == k || j == k)
                        continue;

                    if (!relations[j][k] || !relations[k][i])
                        continue;

                    if (!(i < j && j < k || i > j && j > k))
                        continue;

                    tmp.a = i, tmp.b = j, tmp.c = k;

                    if (visited.find(tmp.hash()) == visited.end()) {
                        chains.push_back(tmp);
                        visited[tmp.hash()] = true;
                    }
                }
            }
        }

        sort(chains.begin(), chains.end(), theTruthIsOutThere);

        rep (i, chains.size()) {
            cout << chains[i].a + 1 << " " << chains[i].b + 1 << " " << chains[i].c + 1 << endl;
        }

        cout << "total:" << chains.size() << endl;
        cout << endl;
    }

    return 0;
}
