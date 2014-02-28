#include <iostream>
#include <cmath>
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

struct stats {
    int zero;
    int positive;
    int negative;
};

int main(void) {
    int N, K;
    stats tmp;
    char command;
    int x, y, index, start, end, result;;
    int *input = new int[100005];

    while (cin >> N >> K) {
        rep (i, N) cin >> input[i];

        int sq = (int)sqrt(N);
        int pieces = N / sq;
        if (N % sq != 0) pieces++;

        vector<stats> info;

        rep (i, pieces) {
            tmp.zero = tmp.positive = tmp.negative = 0;

            for (int j = i * sq; j < (i + 1) * sq && j < N; j++) {
                if (input[j] == 0) tmp.zero += 1;
                else if (input[j] > 0) tmp.positive += 1;
                else tmp.negative += 1;
            }

            info.push_back(tmp);
        }

        while (K--) {
            cin >> command >> x >> y;

            if (command == 'C') {
                x--; // adjust index
                index = x / sq;
                if (input[x] == 0) {
                    info[index].zero -= 1;
                } else if (input[x] > 0) {
                    info[index].positive -= 1;
                } else {
                    info[index].negative -= 1;
                }

                if (y == 0) {
                    info[index].zero += 1;
                } else if (y > 0) {
                    info[index].positive += 1;
                } else {
                    info[index].negative += 1;
                }

                input[x] = y;
            } else if (command == 'P') {
                x--, y--;
                start = x / sq;
                end = y / sq;

                result = 1;

                if (start == end) {
                    REPI (i, x, y) {
                        if (input[i] == 0) result *= 0;
                        else if (input[i] > 0) result *= 1;
                        else result *= -1;
                    }
                } else {

                    for (int i = x; i < min((start + 1) * sq, N); i++) {
                        if (input[i] == 0) result *= 0;
                        else if (input[i] > 0) result *= 1;
                        else result *= -1;
                    }

                    for (int i = y; i >= end * sq; i--) {
                        if (input[i] == 0) result *= 0;
                        else if (input[i] > 0) result *= 1;
                        else result *= -1;
                    }

                    for (int i = start + 1; i < end; i++) {
                        if (info[i].zero > 0) result *= 0;
                        else if (info[i].negative % 2 == 0) result *= 1;
                        else result *= -1;
                    }
                }

                if (result == 0) cout << 0;
                else if (result > 0) cout << "+";
                else cout << "-";
            }
        }

        cout << endl;
    }

    delete input;

    return 0;
}
