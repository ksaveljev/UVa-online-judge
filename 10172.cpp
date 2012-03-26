#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

queue<int> queues[101];

bool job_done(int n) {
    rep (i, n) {
        if (!queues[i].empty())
            return false;
    }
    
    return true;
}

int main(void) {
    int t, n, s, q, queue_size, tmp;

    cin >> t;

    while (t--) {
        cin >> n >> s >> q;

        rep (i, n) {
            cin >> queue_size;

            while (queue_size--) {
                cin >> tmp;
                tmp--;
                queues[i].push(tmp);
            }
        }

        int result_time = 0;
        int current_station = 0;
        stack<int> carrier;

        while (true) {
            if (carrier.empty() && job_done(n)) {
                break;
            }

            // unload as much as possible
            while (!carrier.empty()) {
                if (carrier.top() == current_station) {
                    result_time += 1;
                    carrier.pop();
                } else {
                    if (queues[current_station].size() < q) {
                        queues[current_station].push(carrier.top());
                        carrier.pop();
                        result_time += 1;
                    } else {
                        break;
                    }
                }
            }

            // load as much as possible
            while (carrier.size() < s) {
                if (queues[current_station].empty())
                    break;

                carrier.push(queues[current_station].front());
                queues[current_station].pop();
                result_time += 1;
            }

            current_station++;
            if (current_station == n)
                current_station = 0;

            result_time += 2;
        }

        // last station change is ignored
        result_time -= 2;

        cout << result_time << endl;
    }

    return 0;
}
