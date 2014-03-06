#include <iostream>
#include <vector>
#include <string>
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

struct match {
    int movie;
    int diff;
    match() : movie(0), diff(-1) {}
};

int main(void) {
    int m, q;
    string signature;
    vector<string> movies;

    cin >> m >> q;
    cin.ignore(100, '\n');

    rep (i, m) {
        getline(cin, signature);
        movies.push_back(signature);
    }

    while (q--) {
        getline(cin, signature);
        match result;

        rep (i, m) {
            for (int j = 0, sz = movies[i].size(); j + signature.size() <= sz; j++) {
                int diff = 0;

                for (int k = 0, sz2 = signature.size(); k < sz2; k++) {
                    if (movies[i][j+k] != signature[k]) diff++;
                }

                if (result.diff == -1 || diff < result.diff) {
                    result.movie = i + 1;
                    result.diff = diff;
                }
            }
        }

        cout << result.movie << endl;
    }

    return 0;
}
