#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    string input;
    map<string,int> m;

    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["thirty"] = 30;
    m["forty"] = 40;
    m["fifty"] = 50;
    m["sixty"] = 60;
    m["seventy"] = 70;
    m["eighty"] = 80;
    m["ninety"] = 90;
    m["hundred"] = 100;
    m["thousand"] = 1000;
    m["million"] = 1000000;

    while (getline (cin, input)) {
        istringstream iss(input);

        bool is_negative = false;
        int cur = 0, millions = 0, thousands = 0;

        while (iss >> input) {
            if (input == "negative") {
                is_negative = true;
                continue;
            }

            if (input == "million") {
                millions = cur;
                cur = 0;
            } else if (input == "thousand") {
                thousands = cur;
                cur = 0;
            } else {
                if (input == "hundred") {
                    cur = cur * 100;
                } else {
                    cur += m[input];
                }
            }
        }

        cout << (is_negative ? "-" : "") << millions * 1000000 + thousands * 1000 + cur << endl;
    }

    return 0;
}
