#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int str2int(string s) {
    int result = 0;

    for (int i = 0, sz = s.size(); i < sz; i++) {
        result = result * 10 + (s[i] - '0');
    }

    return result;
}

int main(void) {
    size_t found;
    int duration, pos;
    string input, code, locality, number, subscriber;
    vector<string> codes;
    map< string, pair<string,int> > iddstd;

    while (cin >> code) {
        if (code == "000000")
            break;

        codes.push_back(code);
        cin.get();
        getline(cin, input);

        found = input.find('$');
        locality = string(input.begin(), input.begin() + found);

        iddstd[code] = make_pair(locality, str2int(string(input.begin() + found + 1, input.end())));
    }

    while (cin >> number) {
        if (number == "#")
            break;

        cin >> duration;

        pos = -1;

        for (int i = 0, sz = codes.size(); i < sz; i++) {
            if (int(number.find(codes[i])) == 0) {
                if (codes[i][1] == '0' && codes[i].size() > 2 && number.size() - codes[i].size() > 3 && number.size() - codes[i].size() < 11) {
                    pos = i;
                    break;
                } else if (codes[i][1] != '0' && number.size() - codes[i].size() > 3 && number.size() - codes[i].size() < 8) {
                    pos = i;
                    break;
                }
            }
        }

        if (pos != -1)
            subscriber = number.substr(codes[pos].size());

        if (pos == -1 && number.size() > 0 && number[0] == '0') {
            cout << left << setw(16) << number << setw(35) << "Unknown" << setw(5) << right << duration << setw(13) << "-1.00" << endl;
        } else if (pos == -1 && number.size() > 0 && number[0] != '0') {
            cout << left << setw(16) << number << "Local" << right << setw(30) << number << setw(5) << duration << setw(6) << "0.00" << setw(7) << "0.00" << endl;
        } else {
            cout << left << setw(16) << number << iddstd[codes[pos]].first << right << setw(35 - iddstd[codes[pos]].first.size()) << subscriber << setw(5) << duration << setw(6) << fixed << setprecision(2) << iddstd[codes[pos]].second / 100.0 << setw(7) << iddstd[codes[pos]].second / 100.0 * duration << endl;
        }
    }

    return 0;
}
