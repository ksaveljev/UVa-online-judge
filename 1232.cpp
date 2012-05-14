#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define MAXN 100500
#define LEFT(x) (1+(x*2))
#define RIGHT(x) (2+(x*2))

struct node {
    int update;
    int max_height, min_height;
    int start, end, middle;
} nodes[MAXN * 4];

void init (int index, int start, int end) {
    nodes[index].start = start;
    nodes[index].end = end;
    nodes[index].middle = (nodes[index].start + nodes[index].end) / 2;
    nodes[index].min_height = 0;
    nodes[index].max_height = 0;
    nodes[index].update = -1;

    if (nodes[index].start != nodes[index].end) {
        init(LEFT(index), start, nodes[index].middle);
        init(RIGHT(index), nodes[index].middle+1, end);
    }
}

void set_update (int index, int height) {
    if (height > nodes[index].min_height) {
        nodes[index].update = height;
    } else {
    }
}

void do_update (int index) {
    if (nodes[index].update == -1)
        return;

    if (nodes[index].start == nodes[index].end) {
        if (nodes[index].max_height < nodes[index].update) {
            nodes[index].max_height = nodes[index].update;
            nodes[index].min_height = nodes[index].update;
        }
    } else {

        if (nodes[index].update > nodes[index].max_height) {
            nodes[index].max_height = nodes[index].update;
        }

    }

    if (nodes[index].start != nodes[index].end) {
        set_update(LEFT(index), nodes[index].update);
        set_update(RIGHT(index), nodes[index].update);
    }

    nodes[index].update = -1;
}

void update (int index, int start, int end, int height) {
    if (start <= nodes[index].start && end >= nodes[index].end)
        set_update(index, height);

    do_update(index);

    if (start > nodes[index].end || end < nodes[index].start)
        return;

    if (!(start <= nodes[index].start && end >= nodes[index].end)) {
        update(LEFT(index), start, end, height);
        update(RIGHT(index), start, end, height);

        nodes[index].max_height = max(nodes[LEFT(index)].max_height, nodes[RIGHT(index)].max_height);
        nodes[index].min_height = min(nodes[LEFT(index)].min_height, nodes[RIGHT(index)].min_height);
    }
}

int query (int index, int start, int end, int height) {
    int result = 0;

    do_update(index);

    if (start > nodes[index].end || end < nodes[index].start) {
        result = 0;
    } else if (start <= nodes[index].start && end >= nodes[index].end && nodes[index].max_height <= height) {
        result = nodes[index].end - nodes[index].start + 1;
    } else if (start <= nodes[index].start && end >= nodes[index].end && nodes[index].min_height > height) {
        result = 0;
    } else {
        result = query(LEFT(index), start, end, height) + query(RIGHT(index), start, end, height);
        nodes[index].max_height = max(nodes[LEFT(index)].max_height, nodes[RIGHT(index)].max_height);
        nodes[index].min_height = min(nodes[LEFT(index)].min_height, nodes[RIGHT(index)].min_height);
    }

    return result;
}

int main(void) {
    int number_of_cases, number_of_buildings, start, end, height;

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> number_of_buildings;

        int result = 0;

        init(0, 0, 99999);

        while (number_of_buildings--) {
            cin >> start >> end >> height;

            result += query(0, start, end-1, height);

            update(0, start, end-1, height);
        }

        cout << result << endl;
    }

    return 0;
}
