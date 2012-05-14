#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define LEFT(x) (1+(x*2))
#define RIGHT(x) (2+(x*2))
#define MAXN 1024001

struct node {
    char update;
    int middle, start, end, number_of_bucaneers;
} nodes[MAXN * 4];

bool bucaneer[MAXN];


void init (int index, int start, int end) {
    nodes[index].start = start;
    nodes[index].end = end;
    nodes[index].middle = (start + end) / 2;
    nodes[index].update = ' ';

    if (start == end) {
        nodes[index].number_of_bucaneers = (bucaneer[nodes[index].start] ? 1 : 0);

    } else {
        init (LEFT(index), start, nodes[index].middle);
        init (RIGHT(index), nodes[index].middle + 1, end);
        nodes[index].number_of_bucaneers = nodes[LEFT(index)].number_of_bucaneers + nodes[RIGHT(index)].number_of_bucaneers;
    }
}

void set_update (int index, char command) {
    if (command == 'I') {
        switch (nodes[index].update) {
            case ' ':
                nodes[index].update = 'I';
                break;
            case 'I':
                nodes[index].update = ' ';
                break;
            case 'E':
                nodes[index].update = 'F';
                break;
            case 'F':
                nodes[index].update = 'E';
                break;
        }
    } else {
        nodes[index].update = command;
    }
}

void do_update (int index) {
    if (nodes[index].update == ' ')
        return;

    switch (nodes[index].update) {
        case 'I':
            nodes[index].number_of_bucaneers = nodes[index].end - nodes[index].start + 1 - nodes[index].number_of_bucaneers;
            break;
        case 'E':
            nodes[index].number_of_bucaneers = 0;
            break;
        case 'F':
            nodes[index].number_of_bucaneers = nodes[index].end - nodes[index].start + 1;
            break;
    }

    set_update(LEFT(index), nodes[index].update);
    set_update(RIGHT(index), nodes[index].update);

    nodes[index].update = ' ';
}

int query (int index, int start, int end) {
    int result;

    do_update(index);

    if (start > nodes[index].end || end < nodes[index].start) {
        result = 0;
    } else if (start <= nodes[index].start && end >= nodes[index].end) {
        result = nodes[index].number_of_bucaneers;
    } else {
        result = query(LEFT(index), start, end) + query(RIGHT(index), start, end);
        nodes[index].number_of_bucaneers = nodes[LEFT(index)].number_of_bucaneers + nodes[RIGHT(index)].number_of_bucaneers;
    }

    return result;
}

void update (int index, int start, int end, char command) {
    if (start <= nodes[index].start && end >= nodes[index].end)
        set_update(index, command);

    do_update(index);

    if (start > nodes[index].end || end < nodes[index].start)
        return;

    if (!(start <= nodes[index].start && end >= nodes[index].end)) {
        update(LEFT(index), start, end, command);
        update(RIGHT(index), start, end, command);
        nodes[index].number_of_bucaneers = nodes[LEFT(index)].number_of_bucaneers + nodes[RIGHT(index)].number_of_bucaneers;
    }
}

int main(void) {
    string s;
    char command;
    int number_of_cases, t, m, queries, start, end, query_counter;

    cin >> number_of_cases;

    rep (case_number, number_of_cases) {
        int number_of_pirates = 0;

        cin >> m;

        while (m--) {
            cin >> t >> s;

            rep (i, t) {
                rep (j, s.size()) {
                    bucaneer[number_of_pirates++] = (s[j] == '1' ? true : false);
                }
            }
        }

        init (0, 0, number_of_pirates - 1);

        cout << "Case " << case_number+1 << ":" << endl;

        cin >> queries;
        query_counter = 0;

        while (queries--) {
            cin >> command >> start >> end;

            if (command == 'S') {
                cout << "Q" << ++query_counter << ": " << query(0, start, end) << endl;
            } else {
                update(0, start, end, command);
            }
        }
    }

    return 0;
}
