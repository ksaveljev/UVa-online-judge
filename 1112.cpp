#include <iostream>
#include <queue>
using namespace std;

int field[101][101];

typedef struct _pos {
    int n;
    int timer;
} pos;

struct TheTruthIsOutThere {
    bool operator()(const pos& a, const pos& b) {
        return a.timer < b.timer;
    }
};

int main(void) {
    int t, n, e, timer, m, a, b, c;
    pos tmp;

    cin >> t;

    while (t--) {
        cin >> n >> e >> timer;
        cin >> m;

        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                field[i][j] = -1;
            }
        }

        while (m--) {
            cin >> a >> b >> c;
            field[a][b] = c;
        }

        int result = 0;

        for (int i = 0; i < 101; i++) {
            priority_queue<pos, vector<pos>, TheTruthIsOutThere> pq;
            
            tmp.n = i;
            tmp.timer = 0;
            pq.push(tmp);

            while (!pq.empty()) {
                tmp = pq.top();
                pq.pop();

                if (tmp.n == e) {
                    result++;
                    break;
                }
                
                for (int i = 0; i < 101; i++) {
                    if (field[tmp.n][i] != -1) {
                        pos p;
                        p.n = i;
                        p.timer = tmp.timer + field[tmp.n][i];
                        if (p.timer <= timer)
                            pq.push(p);
                    }
                }
            }
        }

        cout << result << endl;
        if (t > 0) cout << endl;
    }

    return 0;
}
