#include <iostream>
#include <algorithm>
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

struct person {
    string name;
    int year, month, day;
};

bool theTruthIsOutThere(const person &a, const person &b) {
    if (a.year == b.year) {
        if (a.month == b.month) {
            return a.day < b.day;
        } else {
            return a.month < b.month;
        }
    } else {
        return a.year < b.year;
    }
}

int main(void) {
    int n;
    string name;
    vector<person> persons;

    cin >> n;

    while (n--) {
        person p;
        cin >> p.name >> p.day >> p.month >> p.year;
        persons.push_back(p);
    }

    sort(persons.begin(), persons.end(), theTruthIsOutThere);

    cout << persons[sz(persons)-1].name << endl;
    cout << persons[0].name << endl;

    return 0;
}
