#include <iostream>
#include <vector>
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

struct intermediate {
    int camarade;
    int length;
};

int find(int a, int b, int N, vector<int> *camarades) {
    intermediate tmp;
    queue<intermediate> q;
    bool visited[N];

    tmp.camarade = 0;
    tmp.length = 0;

    rep (i, N) visited[i] = false;

    visited[a] = true;

    rep (i, sz(camarades[a])) {
        tmp.camarade = camarades[a][i];
        tmp.length = 0;
        visited[camarades[a][i]] = true;
        q.push(tmp);
    }

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.camarade == b) {
            return tmp.length;
        }

        rep (i, sz(camarades[tmp.camarade])) {
            if (visited[camarades[tmp.camarade][i]]) continue;
            intermediate other;
            other.camarade = camarades[tmp.camarade][i];
            other.length = tmp.length + 1;
            visited[camarades[tmp.camarade][i]] = true;
            q.push(other);
        }
    }

    return -1;
}

int main(void) {
    int cases, N, index, n, a, b, c;

    cin >> cases;

    while (cases--) {
        cin >> N;

        vector<int> *camarades = new vector<int>[N];

        rep (i, N) {
            cin >> index >> n;
            rep (j, n) {
                cin >> c;
                camarades[index].push_back(c);
                camarades[c].push_back(index);
            }
        }

        cin >> a >> b;
        cout << a << " " << b << " " << find(a, b, N, camarades) << endl;

        delete [] camarades;

        if (cases) cout << endl;
    }

    return 0;
}
