#include <iostream>
#include <string>
#include <algorithm>
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
    bool end = false;
    string input;
    string result = "", word = "";
    int longest = 0, current;

    while (getline(cin, input)) {
        current = 0;

        rep (i, sz(input)) {
            if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z' || input[i] == '-') {
                current++;
                word += input[i];
            } else {
                if (word == "E-N-D") {
                    end = true;
                    break;
                }

                if (current > longest) {
                    longest = current;
                    result = word;
                }

                current = 0;
                word = "";
            }
        }

        if (end) break;
    }

    transform(result.begin(), result.end(), result.begin(), ::tolower);
    cout << result << endl;

    return 0;
}
