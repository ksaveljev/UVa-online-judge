#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define custom_abs(x) ((x)<0?-x:x)
typedef long long LL;

typedef struct _tax {
    LL pst, gst, hst;
} tax;

LL read_percentage() {
    char tmp;
    string cents;
    LL result;

    cin >> result >> tmp;
    result *= 100;

    if (tmp == '.') {
        cin >> cents;
        result += (cents[0] - '0') * 10;
        if (cents.size() == 3)
            result += cents[1] - '0';
    }

    return result;
}

LL getdif (LL pay, LL tax) {
    LL tmp = pay * tax;

    return (tmp % 10000 < 5000) ? tmp / 10000 : tmp / 10000 + 1;
}

int main(void) {
    char tmp;
    string category;
    int cases, n, m;

    cin >> cases;

    while (cases--) {
        cin >> n >> m;
        map<string,tax> taxes;

        while (n--) {
            cin >> category;

            tax tmptax;
            tmptax.pst = read_percentage();
            tmptax.gst = read_percentage();
            tmptax.hst = read_percentage();

            taxes[category] = tmptax;
        }


        LL result = 0;

        while (m--) {
            LL dol, pay;
            string cent;

            cin >> category >> tmp >> dol >> tmp >> cent;

            if (cent.size() == 2) {
                pay = dol * 100 + (cent[0] - '0') * 10 + cent[1] - '0';
            } else if (cent.size() == 1) {
                pay = dol * 100 + (cent[0] - '0') * 10;
            }

            result -= getdif(pay, taxes[category].pst);
            result -= getdif(pay, taxes[category].gst);
            result += getdif(pay, taxes[category].hst);
        }

        if (result < 0)
            printf("-%lld.%02lld\n", custom_abs(result/100), custom_abs(result % 100));
        else
            printf("%lld.%02lld\n", result / 100, custom_abs(result % 100));
    }

    return 0;
}
