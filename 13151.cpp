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
#include <sstream>
using namespace std;

int decimal(string& v) {
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        result = result * 10 + int(v[i] - '0');
    }
    return result;
}

int oct2dec(string& v) {
    int result = 0, j = 0;

    for (int i = v.size() - 1; i > 0; i--) {
        int x = int(v[i] - '0');
        result += x * pow(8, j);
        j++;
    }

    return result;
}

int hex2dec(string &v) {
    int result = 0;
    stringstream ss;
    ss << hex << v;
    ss >> result;
    return result;
}

int convert(string& v) {
    if (v[0] != '0') {
        return decimal(v);
    }
    if (v.size() > 1 && v[1] == 'x') {
        return hex2dec(v);
    }
    return oct2dec(v);
}

int main(void) {
    string v;
    int t, r;

    while (cin >> v >> t) {
        if (v == "0" && t == 0) break;

        int x = convert(v);
        int points = 0;

        while (t--) {
            cin >> v >> r;

            if (v == "++i") {
                if (r == x + 1) points++;
                x = r;
            } else if (v == "i++") {
                if (r == x) points++;
                x = r + 1;
            } else if (v == "i--") {
                if (r == x) points++;
                x = r - 1;
            } else if (v == "--i") {
                if (r == x - 1) points++;
                x = r;
            } else if (v == "i") {
                if (r == x) points++;
                x = r;
            }
        }

        cout << points << endl;
    }


    return 0;
}
