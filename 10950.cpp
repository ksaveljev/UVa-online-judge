#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string expected;
int num_of_results;
vector<char> result;
vector< pair<char, string> > codes;

bool theTruthIsOutThere(const pair<char, string> &a, const pair<char, string> &b) {
    return a.first < b.first;
}

bool is_prefix(const string &code) {
    bool ok = true;
    int sz = code.size();

    if (sz > expected.size()) return false;

    for (int i = 0, sz = code.size(); i < sz; i++) {
        if (code[i] != expected[i]) {
            ok = false;
            break;
        }
    }

    return ok;
}

void solve(string code) {
    if (num_of_results == 100) return;

    if (code == expected) {
        num_of_results++;
        for (int i = 0, sz = result.size(); i < sz; i++)
            cout << result[i];
        cout << endl;
        return;
    }

    for (int i = 0, sz = codes.size(); i < sz; i++) {
        result.push_back(codes[i].first);
        if (is_prefix(code + codes[i].second))
            solve(code + codes[i].second);
        if (is_prefix(code + "0" + codes[i].second))
            solve(code + "0" + codes[i].second);
        result.pop_back();
    }
}

int main(void) {
    int n, cases = 0;
    char c;
    string tmp;

    while (cin >> n) {
        if (n == 0) break;

        cases++;
        cout << "Case #" << cases << endl;

        codes.clear();
        result.clear();
        num_of_results = 0;

        for (int i = 0; i < n; i++) {
            cin >> c >> tmp;
            codes.push_back(make_pair(c, tmp));
        }

        sort(codes.begin(), codes.end(), theTruthIsOutThere);

        cin >> expected;

        solve("");
        cout << endl;
    }

    return 0;
}
