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

int calc(string a, string b) {
    int i, j;
    int result = a.size() + b.size();
    for (i = 0; i < a.size(); i++) {
        bool ok = true;
        for (j = 0; j < b.size() && j+i < a.size(); j++) {
            if ((a[i+j] == '1' && b[j] == '2') || (a[i+j] == '2' && b[j] == '1') || (a[i+j] == '1' && b[j] == '1')) {
                continue;
            }
            ok = false;
            break;
        }

        if (ok) {
            int tmp = i + max(a.size() - i, b.size());
            result = min(result, tmp);
        }
    }

    return result;
}

int main(void) {
    string a, b;

    while (cin >> a >> b) {
        if (b.size() > a.size()) swap(a, b);
        int result = a.size() + b.size();
        result = min(result, calc(a, b));
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        result = min(result, calc(a, b));
        cout << result << endl;
    }

    return 0;
}
