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
    int t, n;
    char c;

    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case " << T <<": ";
        cin >> n;
        int counter = 0;
        int result = -1;
        for (int i = 0; i < n; i++) {
            cin >> c;
            if (c == 'W') {
                if (result == -1) {
                    counter = 0;
                }
            } else {
                if (counter == 2) {
                    result = i + 1;
                }
                counter++;
            }
        }
        if (result == -1) {
            cout << "Yay! Mighty Rafa persists!" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
