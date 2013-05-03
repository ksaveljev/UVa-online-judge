#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

string song[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

int main(void) {
    int n;
    string name;
    vector<string> names;

    cin >> n;

    while (n--) {
        cin >> name;
        names.push_back(name);
    }

    int max = names.size () % 16 == 0 ? names.size() : 16 * (names.size() / 16 + 1);

    rep (i, max) {
        cout << names[i%names.size()] << ": " << song[i%16] << endl;
    }

    return 0;
}
