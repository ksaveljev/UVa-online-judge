#include <iostream>
#include <string>
#include <set>
#include <sstream>
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
    set<string> dic;

    while (getline(cin, input)) {
        if (input == "#")
            break;

        dic.insert(input);
    }

    getline(cin, input);

    int max = 0;
    string result = "";

    REP (k, 1, 27) {
        string converted(input);

        rep (i, input.size()) {
            int new_val = (input[i] == ' ' ? k : (input[i] - 'A' + 1) + k) % 27;
            if (new_val == 0)
                converted[i] = ' ';
            else
                converted[i] = new_val - 1 + 'A';
        }

        stringstream ss(converted);

        int count = 0;
        string word;

        while (ss >> word) {
            if (dic.find(word) != dic.end()) {
                count++;
            }
        }

        if (count > max) {
            max = count;
            result = converted;
        }
    }

    // erase trailing spaces
    while (result[result.size()-1] == ' ') {
        result.erase(result.end()-1);
    }

    int start = 0;

    while (true) {
        if (start + 60 >= result.size()) {
            REP (i, start, result.size())
                cout << result[i];
            
            break;
        } else if (result[start + 60] == ' ') {
            int end = start + 60;
            while (result[end] == ' ') end--;

            REPI (i, start, end)
                cout << result[i];

            cout << endl;

            start = start + 60;
            while (result[start] == ' ') start++;
        } else {
            int end = start + 59;

            while (result[end] != ' ') end--;
            while (result[end] == ' ') end--;

            REPI (i, start, end)
                cout << result[i];

            cout << endl;

            start = end + 1;
            while (result[start] == ' ') start++;
        }
    }

    cout << endl;

    return 0;
}
