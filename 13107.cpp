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

int main(void) {
    string input;

    while (getline(cin, input)) {
        int idx = 1;
        map<char,int> m;

        for (int i = 0; i < input.size(); i++) {
            if (m.find(input[i]) == m.end()) {
                if (idx == 2) {
                    m[input[i]] = 5;
                } else if (idx == 5) {
                    m[input[i]] = 2;
                } else if (idx == 6) {
                    m[input[i]] = 9;
                } else if (idx == 9) {
                    m[input[i]] = 6;
                } else if (idx == 12) {
                    m[input[i]] = 15;
                } else if (idx == 15) {
                    m[input[i]] = 12;
                } else if (idx == 16) {
                    m[input[i]] = 19;
                } else if (idx == 19) {
                    m[input[i]] = 16;
                } else if (idx == 20) {
                    m[input[i]] = 50;
                } else if (idx == 21) {
                    m[input[i]] = 51;
                } else if (idx == 22) {
                    m[input[i]] = 55;
                } else if (idx == 23) {
                    m[input[i]] = 53;
                } else if (idx == 24) {
                    m[input[i]] = 54;
                } else if (idx == 25) {
                    m[input[i]] = 52;
                } else if (idx == 26) {
                    m[input[i]] = 59;
                } else {
                    m[input[i]] = idx;
                }
                idx++;
            }
            cout << m[input[i]];
        }
        cout << endl;
    }

    return 0;
}
