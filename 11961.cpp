#include <iostream>
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

void generate_all_dna(string &current, vector<string> &v, int length) {
    static const char elements[4] = {'A', 'C', 'G', 'T'};

    if (length == 0) {
        v.push_back(current);
        return;
    }

    rep (i, 4) {
        string next = current + elements[i];
        generate_all_dna(next, v, length - 1);
    }
}

bool is_mutated(const string &initial, const string &result, int allowed_number_of_changes) {
    int number_of_changes = 0;

    rep (i, initial.size()) {
        if (initial[i] != result[i]) {
            number_of_changes++;
        }
    }

    return number_of_changes <= allowed_number_of_changes;
}

int main(void) {
    int n, k, number_of_cases;
    string input = "";
    vector<string> all[11];

    REPI (i, 1, 10) {
        generate_all_dna(input, all[i], i);
    }

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> n >> k;
        cin.ignore(100, '\n');

        getline(cin, input);

        vector<string> result;

        rep (i, all[n].size()) {
            if (is_mutated(input, all[n][i], k)) {
                result.push_back(all[n][i]);
            }
        }

        cout << result.size() << endl;
        rep (i, result.size()) {
            cout << result[i] << endl;
        }
    }

    return 0;
}
