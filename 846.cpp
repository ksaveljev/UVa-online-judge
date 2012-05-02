#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n, a, b;

    cin >> n;

    while (n--) {
        cin >> a >> b;

        int result, steps = 0, diff = b - a;

        while (true) {
            if (diff == 0) {
                result = 2 * steps;
                break;
            } else if (diff < 2 * (steps + 1)) {
                if (steps + 1 >= diff)
                    result = 2 * steps + 1;
                else
                    result = 2 * steps + 2;

                break;
            }

            steps++;
            diff = b - a - steps * (1 + steps);
        }

        cout << result << endl;
    }

    return 0;
}
