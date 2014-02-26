#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>
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

void load_dictionary(string &input, map<string,string> &dic) {
    vector<string> tokens;

    input = input.substr(1, input.size() - 2);

    replace(input.begin(), input.end(), ',', ' ');
    replace(input.begin(), input.end(), ':', ' ');

    istringstream iss(input);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter< vector<string> >(tokens));

    for (int i = 0, sz = tokens.size(); i < sz; i += 2) {
        dic[tokens[i]] = tokens[i+1];
    }
}

void print_keys(char c, const vector<string> v) {
    if (!v.empty()) {
        cout << c;
        rep (i, v.size()) {
            if (i > 0) cout << ",";
            cout << v[i];
        }
        cout << endl;
    }
}

int main(void) {
    int cases;
    string input;

    cin >> cases;
    cin.ignore(100, '\n');

    while (cases--) {
        map<string,string> old_dic;
        map<string,string> new_dic;

        getline(cin, input);
        load_dictionary(input, old_dic);

        getline(cin, input);
        load_dictionary(input, new_dic);

        vector<string> added_keys, deleted_keys, changed_keys;

        for (map<string,string>::iterator it = old_dic.begin(); it != old_dic.end(); it++) {
            if (new_dic.find(it->first) != new_dic.end()) {
                if (new_dic[it->first] != it->second)
                    changed_keys.push_back(it->first);

                new_dic.erase(it->first);
            } else {
                deleted_keys.push_back(it->first);
            }
        }

        for (map<string,string>::iterator it = new_dic.begin(); it != new_dic.end(); it++) {
            added_keys.push_back(it->first);
        }

        if (added_keys.empty() && deleted_keys.empty() && changed_keys.empty()) {
            cout << "No changes" << endl;
        } else {
            sort(added_keys.begin(), added_keys.end());
            sort(deleted_keys.begin(), deleted_keys.end());
            sort(changed_keys.begin(), changed_keys.end());

            print_keys('+', added_keys);
            print_keys('-', deleted_keys);
            print_keys('*', changed_keys);
        }

        cout << endl;
    }

    return 0;
}
