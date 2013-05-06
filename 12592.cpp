#include <iostream>
#include <string>
#include <map>
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
    int n, q;
    string a, b;
    map<string,string> slogans;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, a);
        getline(cin, b);
        slogans[a] = b;
    }

    cin >> q;
    cin.ignore(100, '\n');

    while (q--) {
        getline(cin, a);
        cout << slogans[a] << endl;
    }

    return 0;
}
