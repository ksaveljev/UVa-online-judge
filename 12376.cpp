#include <iostream>
#include <vector>
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

typedef struct _node {
    int value;
    vector<int> neighbours;
} node;

int main(void) {
    int number_of_cases;
    int n, m, a, b;
    node *nodes;

    cin >> number_of_cases;

    REPI (case_number, 1, number_of_cases) {
        cin >> n >> m;

        nodes = new node[n];

        rep (i, n) {
            cin >> nodes[i].value;
        }

        rep (i, m) {
            cin >> a >> b;
            nodes[a].neighbours.push_back(b);
        }

        int result = 0;
        int current_node = 0;

        while (!nodes[current_node].neighbours.empty()) {
            int next_node = nodes[current_node].neighbours[0];
            int max = nodes[next_node].value;

            REP (i, 1, nodes[current_node].neighbours.size()) {
                int tmp = nodes[current_node].neighbours[i];
                if (nodes[tmp].value > max) {
                    next_node = tmp;
                    max = nodes[next_node].value;
                }
            }

            result += max;
            current_node = next_node;
        }

        cout << "Case " << case_number << ": " << result << " " << current_node << endl;

        delete [] nodes;
    }

    return 0;
}
