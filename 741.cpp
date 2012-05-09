#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

/*
 * Hints on decoding:
 * http://www.cs.princeton.edu/courses/archive/spr03/cs226/assignments/burrows.html
 *
 */

int main(void) {
    int pos;
    string message;
    bool first = true;

    while (cin >> message) {
        int pos;


        cin >> pos;

        if (message == "END" && pos == 0)
            break;

        if (!first)
            cout << endl;

        first = false;

        string tmp(message);

        sort (tmp.begin(), tmp.end());

        int next[tmp.size()];

        int last_pos = -1;

        rep (i, tmp.size()) {
            if (last_pos == -1) {
                int p = message.find(tmp[i]);
                next[i] = p;
                last_pos = p;
            } else {
                if (tmp[i] == tmp[i-1]) {
                    int p = message.find(tmp[i], last_pos + 1);
                    next[i] = p;
                    last_pos = p;
                } else {
                    last_pos = -1;
                    int p = message.find(tmp[i]);
                    next[i] = p;
                    last_pos = p;
                }
            }
        }

        pos--;

        rep (i, message.size()) {
            pos = next[pos];
            cout << message[pos];
        }
        cout << endl;
    }

    return 0;
}
