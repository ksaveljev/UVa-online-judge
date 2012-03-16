#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector< deque<int> > result;

void solve(int n, int div, deque<int> &q) {
    for (int i = div; i * i <= n; i++) {
        if (n % i == 0) {
            q.push_back(i);
            solve(n / i, i , q);
            q.pop_back();
        }
    }

    q.push_back(n);
    result.push_back(q);
    q.pop_back();
}

int main(void) {
    int n;

    while (cin >> n) {
        if (n == 0)
            break;

        result.clear();
        deque<int> q;

        solve(n, 2, q);

        cout << result.size() - 1 << endl;
        for (int i = 0, sz = result.size() - 1; i < sz; i++) {
            for (int j = 0, sz2 = result[i].size(); j < sz2; j++) {
                if (j > 0)
                    cout << " ";
                cout << result[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
