#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int input_size;
string a, b;
deque<char> actions, s;
vector< deque<char> > result;

void solve(int i, int j) {
    if (i == input_size && j == input_size) {
        result.push_back(actions);
        return;
    }

    if (i < input_size) {
        actions.push_back('i');
        s.push_back(a[i]);
        solve(i + 1, j);
        s.pop_back();
        actions.pop_back();
    }

    if (!s.empty() && s.back() == b[j]) {
        actions.push_back('o');
        char tmp = s.back();
        s.pop_back();
        solve(i, j + 1);
        s.push_back(tmp);
        actions.pop_back();
    }
}

int main(void) {
    while (getline(cin, a)) {
        getline(cin, b);

        result.clear();

        string tmp_a(a);
        string tmp_b(b);

        sort(tmp_a.begin(), tmp_a.end());
        sort(tmp_b.begin(), tmp_b.end());

        if (tmp_a != tmp_b) {
            cout << "[" << endl << "]" << endl;
            continue;
        }

        input_size = a.size();

        solve(0, 0);

        cout << "[" << endl;

        rep (i, result.size()) {
            bool first = true;

            while (!result[i].empty()) {
                if (!first)
                    cout << " ";

                first = false;
                cout << result[i].front();
                result[i].pop_front();
            }

            cout << endl;
        }

        cout << "]" << endl;
    }

    return 0;
}
