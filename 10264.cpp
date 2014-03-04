#include <iostream>
#include <vector>
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

struct corner {
    int weight;
    int sum;
    corner() : weight(0), sum(0) {}
};

int main(void) {
    int N;

    while (cin >> N) {
        int number_of_corners = 1 << N;
        vector<corner> corners;

        rep (i, number_of_corners) {
            corner tmp;
            cin >> tmp.weight;
            corners.push_back(tmp);
        }

        rep (i, number_of_corners) {
            rep (j, N) {
                corners[i].sum += corners[(i ^ (1 << j))].weight;
            }
        }

        int result = 0;

        rep (i, number_of_corners) {
            rep (j, N) {
                result = max(result, corners[i].sum + corners[(i ^ (1 << j))].sum);
            }
        }

        cout << result << endl;
    }

    return 0;
}
