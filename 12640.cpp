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

int main(void) {
    string input;

    while (getline(cin, input)) {
        stringstream ss(input);

        int result = 0;
        int a = 0;
        int x;
        while (ss >> x) {
            a += x;
            result = max(result, a);
            a = max(a, 0);
        }
        cout << result << endl;
    }

    return 0;
}
