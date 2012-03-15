#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, first, last, current, sz;
    bool increasing;

    while (cin >> n) {
        if (n == 0)
            break;

        increasing = true;
        vector<int> points;

        for (int i = 0; i < n; i++) {
            cin >> current;

            if (i == 0)
                first = current;

            if (i == n - 1)
                last = current;

            if (points.size() < 2) {
                points.push_back(current);
                continue;
            }

            sz = points.size();

            increasing = (points[sz-1] > points[sz-2]);

            if (current > points[sz-1] && increasing)
                points[sz-1] = current;
            else if (current < points[sz-1] && !increasing)
                points[sz-1] = current;
            else if (current > points[sz-1]) {
                increasing = true;
                points.push_back(current);
            } else if (current < points[sz-1]) {
                increasing = false;
                points.push_back(current);
            }
        }

        sz = points.size();
        int result = sz;

        bool last_growing = (points[sz-2] < points[sz-1]);
        bool first_growing = (points[1] > points[0]);

        if (last_growing && points[0] > points[sz-1])
            result--;
        else if (first_growing && points[0] > points[sz-1])
            result--;
        else if (!last_growing && points[0] < points[sz-1])
            result--;
        else if (!first_growing && points[0] < points[sz-1])
            result--;

        cout << result << endl;
    }

    return 0;
}
