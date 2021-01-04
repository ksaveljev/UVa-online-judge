#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

vector<string> input;

string one[5] = {
    ".*.",
    ".*.",
    ".*.",
    ".*.",
    ".*."
};

string two[5] = {
    "***",
    "..*",
    "***",
    "*..",
    "***"
};

string three[5] = {
    "***",
    "..*",
    "***",
    "..*",
    "***"
};

bool is_it(string num[5], int col) {
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < 3; i++) {
            if (input[row][col + i] != num[row][i])
                return false;
        }
    }
    return true;
}

bool is_one(int col) {
    return is_it(one, col);
}

bool is_two(int col) {
    return is_it(two, col);
}

bool is_three(int col) {
    return is_it(three, col);
}

int main(void) {
    int n;
    string str;

    cin >> n;
    getline(cin, str);

    for (int i = 0; i < 5; i++) {
        getline(cin, str);
        input.push_back(str);
    }

    for (int i = 0; i < n; i++) {
        int start = i * 4;
        if (is_one(start)) {
            cout << 1;
        } else if (is_two(start)) {
            cout << 2;
        } else if (is_three(start)) {
            cout << 3;
        }
    }
    cout << endl;

    return 0;
}
