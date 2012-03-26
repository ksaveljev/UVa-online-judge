#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    string input;

    while (getline (cin, input)) {
        bool valid = true;
        stack<int> s;
        vector<int> sizes;

        istringstream iss(input);
        copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(sizes));

        rep (i, sizes.size()) {
            if (sizes[i] < 0) {
                s.push(sizes[i]);
            } else {
                int sum = 0;
                bool found = false;

                while (!s.empty()) {
                    if (s.top() + sizes[i] == 0) {
                        s.pop();
                        s.push(sizes[i]);
                        found = true;
                        break;
                    }

                    if (s.top() < 0) {
                        valid = false;
                        break;
                    }

                    sum += s.top();
                    s.pop();

                    if (sum >= sizes[i]) {
                        valid = false;
                        break;
                    }
                }

                if (!found) {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                break;
        }

        while (!s.empty()) {
            if (s.top() < 0) {
                valid = false;
                break;
            }

            s.pop();
        }

        cout << (valid ? ":-) Matrioshka!" : ":-( Try again.") << endl;
    }

    return 0;
}
