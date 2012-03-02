#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int find_difference(string &dic, string &input) {
    int diff = 0;

    if (dic.size() == input.size()) {
        for (int i = 0, sz = dic.size(); i < sz; i++)
            if (dic[i] != input[i])
                diff++;
    } else {
        string &a = (dic.size() > input.size() ? dic : input);
        string &b = (dic.size() > input.size() ? input : dic);

        for (int i = 0, j = 0, sz1 = a.size(), sz2 = b.size(); i < sz1 && j < sz2; ) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                diff++;
                i++;
            }
        }
    }

    return diff;
}

void automatic_correction(string &input, vector< pair<string,int> > &dictionary, map<string,bool> &m) {
    if (m.find(input) != m.end()) {
        cout << input << " is correct" << endl;
        return;
    }

    int input_length = input.size();

    cout << input << ":";

    for (int i = 0, sz = dictionary.size(); i < sz; i++) {
        if (abs(dictionary[i].second - input_length) > 1)
            continue;

        if (find_difference(dictionary[i].first, input) < 2)
            cout << " " << dictionary[i].first;
    }

    cout << endl;
}

int main(void) {
    int n;
    bool first = true;
    string input;
    map<string,bool> m;
    vector< pair<string,int> > dictionary;

    cin >> n;
    getline(cin, input); // \n after n

    while (n--) {
        getline(cin, input); // empty line

        if (!first)
            cout << endl;
        first = false;

        dictionary.clear();
        m.clear();

        while (getline(cin, input)) {
            if (input == "#")
                break;

            dictionary.push_back(make_pair(input, input.size()));
            m[input] = true;
        }

        while (getline(cin, input)) {
            if (input == "#")
                break;

            automatic_correction(input, dictionary, m);
        }
    }

    return 0;
}
