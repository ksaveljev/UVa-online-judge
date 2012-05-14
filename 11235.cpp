#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define MAXN 200010
#define LEFT(x) (1+(x*2))
#define RIGHT(x) (2+(x*2))

struct node {
    int max_reps;
    int start, end, middle;
} nodes[MAXN * 4];

int start[MAXN], end[MAXN], values[MAXN];


void init (int index, int _start, int _end) {
    nodes[index].start = _start;
    nodes[index].end = _end;
    nodes[index].middle = (nodes[index].start + nodes[index].end) / 2;

    int z = values[nodes[index].middle];

    if (nodes[index].start == nodes[index].end) {
        nodes[index].max_reps = 1;
    } else {
        init(LEFT(index), _start, nodes[index].middle);
        init(RIGHT(index), nodes[index].middle+1, _end);

        nodes[index].max_reps = max(nodes[LEFT(index)].max_reps, nodes[RIGHT(index)].max_reps);
        nodes[index].max_reps = max(nodes[index].max_reps, min(end[z], nodes[index].end) - max(start[z], nodes[index].start) + 1);
    }
}

int query (int index, int _start, int _end) {
    if (_start > nodes[index].end || _end < nodes[index].start)
        return 0;

    if (_start <= nodes[index].start && _end >= nodes[index].end)
        return nodes[index].max_reps;

    int z = max(query(LEFT(index), _start, _end), query(RIGHT(index), _start, _end));

    return max(z, min(end[values[nodes[index].middle]], _end) - max(start[values[nodes[index].middle]], _start) + 1);
}

int main(void) {
    int n, q, s, e, previous = 200005;

    while (cin >> n) {
        if (n == 0)
            break;

        cin >> q;

        rep (i, n) {
            cin >> values[i];
            values[i] += 100000;

            if (values[i] != previous) {
                start[values[i]] = i;
                end[previous] = i - 1;
            }

            previous = values[i];
        }

        end[values[n-1]] = n-1;

        init(0, 0, n-1);

        while (q--) {
            cin >> s >> e;

            cout << query(0, --s, --e) << endl;
        }
    }

    return 0;
}
