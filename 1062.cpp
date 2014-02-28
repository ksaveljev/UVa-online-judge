#include <iostream>
#include <stack>
#include <string>
#include <vector>
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
    string input;
    int case_number = 0;

    while (getline(cin, input)) {
        if (input == "end") break;

        vector< stack<char> > stacks;

        rep (i, input.size()) {
            bool found = false;

            rep (j, stacks.size()) {
                if (stacks[j].top() >= input[i]) {
                    found = true;
                    stacks[j].push(input[i]);
                    break;
                }
            }

            if (!found) {
                stack<char> tmp;
                tmp.push(input[i]);
                stacks.push_back(tmp);
            }
        }

        case_number++;
        cout << "Case " << case_number << ": " << stacks.size() << endl;
    }

    return 0;
}
