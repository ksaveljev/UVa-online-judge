#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    ios::sync_with_stdio(false);

    int k, number_of_cases, tmp;

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> k;

        vector<int> nums[501];

        REP (i, 1, k+1) {
            nums[i/500].push_back(i);
        }

        bool first = true;

        while (k--) {
            cin >> tmp;

            if (!first)
                cout << " ";
            else
                first = false;

            int index = 0;

            while (tmp >= nums[index].size()) {
                tmp -= nums[index].size();
                index++;
            }

            cout << nums[index][tmp];
            nums[index].erase(nums[index].begin() + tmp);
        }

        cout << endl;
    }

    return 0;
}
