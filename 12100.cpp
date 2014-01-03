#include <iostream>
#include <queue>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int test_cases, n, m, priority, highest_priority;

    cin >> test_cases;

    while (test_cases--) {
        cin >> n >> m;

        queue<int> jobs;
        priority_queue<int> priorities;

        rep (i, n) {
            cin >> priority;
            jobs.push(priority);
            priorities.push(priority);
        }

        int time = 0;
        bool finished = false;

        while (!finished) {
            highest_priority = priorities.top();
            priorities.pop();

            while (true) {
                priority = jobs.front();
                jobs.pop();

                if (priority == highest_priority) {
                    time++;
                    if (m == 0) {
                        finished = true;
                    } else {
                        m--;
                    }
                    break;
                } else {
                    jobs.push(priority);
                }

                m--;
                if (m < 0) {
                    m = jobs.size() - 1;
                }
            }
        }

        cout << time << endl;
    }

    return 0;
}
