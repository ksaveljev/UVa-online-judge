#include <iostream>
#include <vector>
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

struct triple {
    int a, b, c;
    triple (int a, int b, int c) : a(a), b(b), c(c) {}
};

int main(void) {
    int n, results[101][101];

    while (cin >> n) {
        rep (i, n) {
            rep (j, n) {
                cin >> results[i][j];
            }
        }

        int counter = 0;
        vector<triple> triples;

        rep (i, n) {
            rep (j, n) {
                rep (k, n) {
                    if ((i < j && j < k) || (i > j && j > k)) {
                        if (results[i][j] == 1 && results[j][k] == 1 && results[k][i] == 1) {
                            counter++;
                            triples.push_back(triple(i+1, j+1, k+1));
                        }
                    }

                    if (i < j && j < k) {
                        if (results[i][j] == 0 && results[j][i] == 0 && results[i][k] == 0 && results[k][i] == 0 && results[j][k] == 0 && results[k][j] == 0) {
                            counter++;
                            triples.push_back(triple(i+1, j+1, k+1));
                        }
                    }
                }
            }
        }

        cout << counter << endl;
        rep (i, triples.size()) {
            cout << triples[i].a << " " << triples[i].b << " " << triples[i].c << endl;
        }
    }

    return 0;
}
