#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

pair<int,int> findBlockPosition(string &input, int index) {
    int start, end;

    start = end = index;

    for (int i = index; i >= 0; i--) {
        if (input[i] == 'x')
            continue;
        else if (input[i] == input[index])
            start = i;
        else
            break;
    }

    for (int i = index, sz = input.size(); i < sz; i++) {
        if (input[i] == 'x')
            continue;
        else if (input[i] == input[index])
            end = i;
        else
            break;
    }

    return make_pair(start, end);
}

int solve(string &input) {
    pair<int,int> prev = make_pair(-1,-1);

    bool ok = true;
    for (int i = 0, sz = input.size(); i < sz; i++) {
        if (input[i] != 'x') {
            ok = false;
            break;
        }
    }

    if (ok)
        return 1;

    for (int i = 0, sz = input.size(); i < sz; i++) {
        if (input[i] == 'x')
            continue;

        pair<int,int> pos = findBlockPosition(input, i);

        if (pos.first == prev.first && pos.second == prev.second || pos.first == pos.second)
            continue;

        prev = pos;

        string tmp(input);
        for (int j = pos.first; j <= pos.second; j++) {
            tmp[j] = 'x';
        }

        if (solve(tmp) == 1)
            return 1;
    }

    return 0;
}

int main(void) {
    int numberOfCases;
    string input;

    cin >> numberOfCases;
    cin.ignore(100, '\n');

    while (numberOfCases--) {
        getline(cin, input);

        cout << solve(input) << endl;
    }


    return 0;
}
