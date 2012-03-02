#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool is_extra_or_missing(string &a, string &b) {
    int diff = 0;
    string &shorter = (a.size() > b.size() ? b : a);
    string &longer = (a.size() > b.size() ? a : b);

    for (int i = 0, j = 0, sz1 = longer.size(), sz2 = shorter.size(); i < sz1 && j < sz2; ) {
        if (longer[i] == shorter[j]) {
            i++; j++;
        } else {
            diff++;
            i++;

            if (diff > 1)
                return false;
        }
    }

    return true;
}

void find_difference(string &a, string &b, vector<int> &pos) {
    for (int i = 0, sz = a.size(); i < sz; i++) {
        if (a[i] != b[i]) {
            pos.push_back(i);

            if (pos.size() > 2)
                return;
        }
    }
}

void automatic_correction(string &input, vector< pair<string,int> > &dictionary, map<string,bool> &m) {
    vector<int> pos;
    int input_size = input.size();
    bool found = false;

    if (m.find(input) != m.end()) {
        cout << input << " is correct" << endl;
        return;
    }

    for (int i = 0, sz = dictionary.size(); i < sz; i++) {
        if (abs(dictionary[i].second - input_size) > 1)
            continue;

        if (dictionary[i].second == input_size) {
            pos.clear();
            find_difference(input, dictionary[i].first, pos);

            if (pos.size() == 1) {
                found = true;
                cout << input << " is a misspelling of " << dictionary[i].first << endl;
                break;
            } else if (pos.size() == 2) {
                if (pos[0] + 1 == pos[1] && input[pos[0]] == dictionary[i].first[pos[1]] && input[pos[1]] == dictionary[i].first[pos[0]]) {
                    found = true;
                    cout << input << " is a misspelling of " << dictionary[i].first << endl;
                    break;
                }
            } 
        } else {
            if (is_extra_or_missing(input, dictionary[i].first)) {
                found = true;
                cout << input << " is a misspelling of " << dictionary[i].first << endl;
                break;
            }
        }
    }

    if (!found)
        cout << input << " is unknown" << endl;
}

int main(void) {
    int n, q;
    string input;
    vector< pair<string,int> > dictionary;
    map<string, bool> m;

    cin >> n;
    getline(cin, input); // \n after n

    while (n--) {
        getline(cin, input);
        dictionary.push_back(make_pair(input, input.size()));
        m[input] = true;
    }

    cin >> q;
    getline(cin, input); // \n after q

    while (q--) {
        getline(cin, input);

        automatic_correction(input, dictionary, m);
    }

    return 0;
}
