#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int n;
int count;
int nums[5];
bool solution_found;

bool is_sorted() {
    bool sorted = true;

    REP (i, 1, n) {
        if (nums[i] < nums[i-1])
            sorted = false;
    }

    return sorted;
}

void solve(int depth, int maxdepth) {
    if (depth == maxdepth) {
        if (is_sorted()) {
            solution_found = true;
            count++;
        }
        return;
    }

    REP (i, 1, n) {
        swap (nums[i], nums[i-1]);
        solve (depth + 1, maxdepth);
        swap (nums[i], nums[i-1]);
    }
}

int main(void) {
    int dataset = 0;

    while (cin >> n) {
        if (n == 0)
            break;

        dataset++;

        rep (i, n)
            cin >> nums[i];

        count = 0;
        solution_found = false;

        for (int i = 0; ; i++) {
            solve (0, i);

            if (solution_found) {
                if (i == 0)
                    count = 0;

                break;
            }
        }

        cout << "There are " << count << " swap maps for input data set " << dataset << "." << endl;
    }

    return 0;
}
