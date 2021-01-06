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
    int t;
    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case " << T << ": ";

        int m, n;
        cin >> m >> n;

        vector<string> A;
        string input;
        getline(cin, input); // \n

        while (m--) {
            getline(cin, input);
            A.push_back(input);
        }

        set<string> result;
        while (n--) {
            getline(cin, input);
            for (int i = 0; i < A.size(); i++) {
                result.insert(A[i] + input);
            }
        }

        cout << result.size() << endl;
    }

    return 0;
}
