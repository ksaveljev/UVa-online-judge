#include <iostream>
#include <map>
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

int main(void) {
    int n, v;

    while (cin >> n) {
        map<int,int> m;
        vector<int> start, finish;

        rep (i, n) {
            cin >> v;
            start.push_back(v);
        }

        rep (i, n) {
            cin >> v;
            finish.push_back(v);
            m[v] = i;
        }

        rep (i, n) {
            start[i] = m[start[i]];
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j + 1 < n; j++) {
                if (start[j] > start[j+1]) {
                    result++;
                    swap(start[j], start[j+1]);
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
