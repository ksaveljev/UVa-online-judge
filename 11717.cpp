#include <iostream>
using namespace std;

int main(void) {
    int t, n, i, k, ignored, inactive, active, case_num = 0, timems;

    cin >> t;

    while (t--) {
        case_num++;
        ignored = inactive = active = 0;

        cin >> n >> i >> k;

        while (n--) {
            cin >> timems;

            if (timems < active)
                ignored++;
            else if (timems >= active + i) {
                inactive++;
                active = timems + k;
            }

            if (timems > active)
                active = timems;
        }

        cout << "Case " << case_num << ": " << inactive << " " << ignored << endl;
    }

    return 0;
}
