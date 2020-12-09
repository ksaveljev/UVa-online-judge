#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main(void) {
    int t;
    int p, c;

    cin >> t;

    while (t--) {
        cin >> p >> c;
        vector<int> producers(p);
        vector<int> consumers(c);
        vector<int> values;

        for (int& x: producers) {
            cin >> x;
            values.push_back(x);
        }

        for (int& x: consumers) {
            cin >> x;
            values.push_back(x);
        }

        values.push_back(0);

        sort(producers.begin(), producers.end());
        sort(consumers.begin(), consumers.end());

        if (p == 0) {
            cout << "0 0" << endl;
            continue;
        }

        if (c == 0) {
            cout << producers[p-1] << " 0" << endl;
            continue;
        }

        pair<int,int> best = make_pair(1e9+5, 1e9+5);

        for (int i = 0; i < values.size(); i++) {
            int idx = upper_bound(producers.begin(), producers.end(), values[i]) - producers.begin();
            int angry = p - idx;

            idx = lower_bound(consumers.begin(), consumers.end(), values[i]) - consumers.begin();
            angry += idx;

            if (angry < best.first) {
                best.first = angry;
                best.second = values[i];
            } else if (angry == best.first && values[i] < best.second) {
                best.second = values[i];
            }
        }

        cout << best.second << " " << best.first << endl;
    }

    return 0;
}
