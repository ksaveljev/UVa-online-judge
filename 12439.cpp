#include <iostream>
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

string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int month_to_int(const string& month) {
    rep (i, 12) {
        if (month == months[i])
            return i+1;
    }

    return -1;
}

int main(void) {
    int t, d1, m1, y1, d2, m2, y2, result;
    char ignore;
    string month;

    cin >> t;

    REPI (case_number, 1, t) {
        cin >> month >> d1 >> ignore >> y1;
        m1 = month_to_int(month);

        cin >> month >> d2 >> ignore >> y2;
        m2 = month_to_int(month);

        if (m1 > 2)
            y1++;

        if (m2 < 2 || m2 == 2 && d2 < 29)
            y2--;

        result = y2 / 4 - (y1 - 1) / 4;
        result -= y2 / 100 - (y1 - 1) / 100;
        result += y2 / 400 - (y1 - 1) / 400;

        cout << "Case " << case_number << ": " << result << endl;
    }

    return 0;
}
