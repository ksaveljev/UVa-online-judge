#include <iostream>
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

bool is_leap(int year) {
    if (year % 4 == 0) {
        if (year % 400 == 0) {
            return true;
        } else if (year % 100 == 0) {
            return false;
        } else {
            return true;
        }
    }

    return false;
}

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void calculate_next_day(int d, int m, int y, int &next_d, int &next_m, int &next_y) {
    d++;
    bool modified = true;

    while (modified) {
        modified = false;

        if (is_leap(y)) {
            days[1] = 29;
        } else {
            days[1] = 28;
        }

        if (m > 12) {
            m = 1;
            y++;
            modified = true;
        } else if (d > days[m-1]) {
            d -= days[m-1];
            m++;
            modified = true;
        }
    }

    next_d = d;
    next_m = m;
    next_y = y;
}

int main(void) {
    int n;
    int d, m, y, c, count, sum;
    int next_d, next_m, next_y, prev_c;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        count = sum = next_d = next_m = next_y = prev_c = 0;

        rep (i, n) {
            cin >> d >> m >> y >> c;

            if (d == next_d && m == next_m && y == next_y) {
                count++;
                sum += c - prev_c;
            }

            calculate_next_day(d, m, y, next_d, next_m, next_y);
            prev_c = c;
        }

        cout << count << " " << sum << endl;
    }

    return 0;
}
