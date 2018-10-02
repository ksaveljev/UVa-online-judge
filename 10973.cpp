#include <iostream>
using namespace std;

bool adj[3001][3001];

int main(void) {
    int t, n, m, a, b;

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < 3001; i++)
            for (int j = 0; j < 3001; j++)
                adj[i][j] = false;

        while (m--) {
            cin >> a >> b;
            adj[a][b] = true;
            adj[b][a] = true;
        }

        int result = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!adj[i][j]) continue;
                for (int k = j + 1; k <= n; k++) {
                    if (adj[i][k] && adj[j][k]) result++;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
