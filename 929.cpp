#include <iostream>
#include <queue>
using namespace std;

int field[1000][1000];
bool visited[1000][1000];

typedef struct _pos {
    int row;
    int col;
    int len;
} pos;

struct TheTruthIsOutThere
{
    bool operator()(const pos& a, const pos& b) {
        return a.len > b.len;
    }
};

int main(void) {
    int t, n, m;
    int nr, nc;
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
                visited[i][j] = false;
            }
        }

        priority_queue<pos, vector<pos>, TheTruthIsOutThere> pq;
        pos tmp;
        tmp.row = 0;
        tmp.col = 0;
        tmp.len = field[0][0];
        pq.push(tmp);
        visited[0][0] = true;

        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();

            if (tmp.row == n-1 && tmp.col == m-1) {
                cout << tmp.len << endl;
                break;
            }

            for (int i = 0; i < 4; i++) {
                nr = tmp.row + dir[i][0];
                nc = tmp.col + dir[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pos p;
                    p.row = nr;
                    p.col = nc;
                    p.len = tmp.len + field[nr][nc];
                    pq.push(p);
                }
            }
        }
    }

    return 0;
}
