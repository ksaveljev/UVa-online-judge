#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct _mxentry {
    string wildcard;
    int priority;
    string machine;
} mx;

bool theTruthIsOutThere(const mx &a, const mx &b) {
    return a.priority < b.priority;
}

int str2int(string &s) {
    int result = 0;

    for (int i = 0, sz = s.size(); i < sz; i++) {
        result = result * 10 + (s[i] - '0');
    }

    return result;
}

bool wildcard_matches(string &wildcard, string machine) {
    bool result = true;
    int w = wildcard.size() - 1, m = machine.size() - 1, i = 0;

    while (wildcard[w-i] != '*') {
        if (wildcard[w-i] != machine[m-i]) {
            result = false;
            break;
        }

        i++;
    }

    return result;
}

void print_resolution(string machine, map<string,bool> &enabled, vector<mx> &mxentries) {
    bool found = false, good = false;

    cout << machine << " =>";

    for (int i = 0, sz = mxentries.size(); i < sz; i++) {
        if (mxentries[i].wildcard[0] == '*') {
            if (!enabled[mxentries[i].machine])
                continue;

            if (wildcard_matches(mxentries[i].wildcard, machine)) {
                cout << " " << mxentries[i].machine;
                break;
            }
        } else if (mxentries[i].wildcard == machine) {
            if (!enabled[mxentries[i].machine])
                continue;

            cout << " " << mxentries[i].machine;
            break;
        }
    }

    cout << endl;
}

int main(void) {
    int n;
    char c;
    mx tmpentry;
    string input, prev, machine;
    vector<mx> mxentries;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, input);

        vector<string> tmp;
        istringstream iss(input);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tmp));

        if (tmp.size() == 2) {
            tmpentry.wildcard = prev;
            tmpentry.priority = str2int(tmp[0]);
            tmpentry.machine = tmp[1];
        } else {
            prev = tmp[0];
            tmpentry.wildcard = tmp[0];
            tmpentry.priority = str2int(tmp[1]);
            tmpentry.machine = tmp[2];
        }

        mxentries.push_back(tmpentry);
    }

    sort(mxentries.begin(), mxentries.end(), theTruthIsOutThere);

    /*
    for (int i = 0, sz = mxentries.size(); i < sz; i++) {
        cout << mxentries[i].wildcard << " " << mxentries[i].priority << " " << mxentries[i].machine << endl;
    }
    */

    // save state of the box
    // it can be either up or down
    // initially all boxes are up
    // (or enabled in our sitation)
    map<string,bool> enabled;

    for (int i = 0, sz = mxentries.size(); i < sz; i++) {
        enabled[mxentries[i].machine] = true;
    }

    while (cin >> c) {
        if (c == 'X')
            break;

        cin >> machine;

        switch (c) {
            case 'A':
                print_resolution(machine, enabled, mxentries);
                break;
            case 'D':
                enabled[machine] = false;
                break;
            case 'U':
                enabled[machine] = true;
                break;
        }
    }

    return 0;
}
