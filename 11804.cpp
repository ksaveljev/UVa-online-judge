#include <iostream>
#include <string>
#include <algorithm>
#include <set>
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

struct player {
    string name;
    int attack;
    int defense;
};

bool theTruthIsOutThere(const player &a, const player &b) {
    return a.attack > b.attack || (a.attack == b.attack && a.defense < b.defense) || (a.attack == b.attack && a.defense == b.defense && a.name < b.name);
}

bool byName(const player &a, const player &b) {
    return a.name < b.name;
}

int main(void) {
    int number_of_cases;
    player players[10];

    cin >> number_of_cases;

    REPI (case_number, 1, number_of_cases) {
        rep (i, 10) {
            cin >> players[i].name >> players[i].attack >> players[i].defense;
        }

        sort (players, players + 10, theTruthIsOutThere);
        sort (players, players + 5, byName);
        sort (players + 5, players + 10, byName);

        cout << "Case " << case_number << ":" << endl;
        cout << "(";
        rep (i, 5) {
            if (i > 0) cout << ", ";
            cout << players[i].name;
        }
        cout << ")" << endl;
        cout << "(";
        rep (i, 5) {
            if (i > 0) cout << ", ";
            cout << players[i+5].name;
        }
        cout << ")" << endl;
    }

    return 0;
}
