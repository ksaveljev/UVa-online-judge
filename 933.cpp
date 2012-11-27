#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

pair<char,int> find_value(string &input) {
    char name;
    int value;
    string tmp;
    stringstream ss(input);

    getline(ss, tmp, '=');
    name = tmp[0];

    getline(ss, tmp);
    stringstream s(tmp);
    s >> value;

    return make_pair(name, value);
}

vector< pair<char,int> > find_pairs(string &input) {
    string tmp;
    vector< pair<char,int> > pairs;
    vector<string> tokens;
    istringstream iss(input);

    while (getline(iss, tmp, ';')) {
        tokens.push_back(tmp);
    }

    for (int i = 0, sz = tokens.size(); i < sz; i++) {
        pairs.push_back(find_value(tokens[i]));
    }

    return pairs;
}

void print_header(const vector< pair<char,int> > &deposits) {
    cout << "  t";

    for (int i = 0, sz = deposits.size(); i < sz; i++) {
        cout << "   " << deposits[i].first;
    }

    cout << endl;

    for (int i = 0, sz = deposits.size() * 4 + 3; i < sz; i++) {
        cout << "-";
    }

    cout << endl;
}

void print_current_values(int time, const vector< pair<char,int> > &deposits) {
    cout << right << setw(3) << time;

    for (int i = 0, sz = deposits.size(); i < sz; i++) {
        cout << right << setw(4) << deposits[i].second;
    }

    cout << endl;
}

int main(void) {
    string input;
    pair<char, int> n;
    bool first = true;

    while (getline(cin, input)) {
        if (!first)
            cout << endl;

        n = find_value(input);

        getline(cin, input);
        vector< pair<char,int> > deposits = find_pairs(input);

        getline(cin, input);
        vector< pair<char,int> > pipes = find_pairs(input);

        print_header(deposits);

        int time = 0;

        while (true) {
            print_current_values(time, deposits);

            bool done = true;

            for (int i = 0, sz = deposits.size(); i < sz - 1; i++) {
                if (deposits[i].second != 0) {
                    done = false;
                    break;
                }
            }

            if (done)
                break;

            time++;

            for (int i = deposits.size() - 1; i > 0; i--) {
                int diff = min(pipes[i-1].second, deposits[i-1].second);
                deposits[i].second += diff;
                deposits[i-1].second -= diff;
            }
        }

        first = false;
    }

    return 0;
}
