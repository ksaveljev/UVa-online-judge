#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define MAXN 200005
#define LEFT(x) (1+(x*2))
#define RIGHT(x) (2+(x*2))

struct node {
    int sum;
    int start, end, middle;
} nodes[MAXN * 4];

int potmeters[MAXN];

void init (int index, int start, int end) {
    nodes[index].start = start;
    nodes[index].end = end;
    nodes[index].middle = (nodes[index].start + nodes[index].end) / 2;

    if (nodes[index].start == nodes[index].end) {
        nodes[index].sum = potmeters[nodes[index].start];
    } else {
        init(LEFT(index), start, nodes[index].middle);
        init(RIGHT(index), nodes[index].middle+1, end);

        nodes[index].sum = nodes[LEFT(index)].sum + nodes[RIGHT(index)].sum;
    }
}

void update (int index, int node_num, int value) {
    if (node_num < nodes[index].start || node_num > nodes[index].end)
        return;

    if (nodes[index].start == nodes[index].end && nodes[index].start == node_num)
        nodes[index].sum = value;
    else {
        update(LEFT(index), node_num, value);
        update(RIGHT(index), node_num, value);

        nodes[index].sum = nodes[LEFT(index)].sum + nodes[RIGHT(index)].sum;
    }
}

int query (int index, int start, int end) {
    int result = 0;

    if (start > nodes[index].end || end < nodes[index].start)
        result = 0;
    else if (start <= nodes[index].start && end >= nodes[index].end)
        result = nodes[index].sum;
    else {
        result = query(LEFT(index), start, end) + query(RIGHT(index), start, end);
    }

    return result;
}

int main(void) {
    bool first_case = true;
    int n, a, b, case_number = 0;
    string command;

    while (cin >> n) {
        if (n == 0)
            break;

        if (!first_case)
            cout << endl;

        first_case = false;

        rep (i, n) {
            cin >> potmeters[i];
        }

        init (0, 0, n-1);

        cout << "Case " << ++case_number << ":" << endl;

        while (cin >> command) {
            if (command == "END")
                break;

            cin >> a >> b;

            if (command == "S") {
                update(0, --a, b);
            } else if (command == "M") {
                cout << query(0, --a, --b) << endl;
            }
        }
    }

    return 0;
}
