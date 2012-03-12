#include <iostream>
#include <string>
using namespace std;

string NUMS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/*
 * returns a pair of values:
 * sum of all chars in the string in decimal
 * minimum possible base
 */
pair<int,int> count_sum(string &s) {
    pair<int,int> result = make_pair(0,0);
    size_t found;

    for (int i = 0, sz = s.size(); i < sz; i++) {
        found = NUMS.find(s[i]);

        result.first += int(found);
        if (int(found) > result.second)
            result.second = int(found);
        }

    return result;
}

int main(void) {
    string number;

    while (cin >> number) {
        if (number[0] == '-' || number[0] == '+')
            number = string(number.begin() + 1, number.end());

        pair<int,int> p = count_sum(number);
        bool found = false;

        // special case
        if (p.second == 0)
            p.second = 1;

        for (int i = p.second + 1; i < 63; i++) {
            if (p.first % (i-1) == 0) {
                cout << i << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "such number is impossible!" << endl;
        }
    }

    return 0;
}
