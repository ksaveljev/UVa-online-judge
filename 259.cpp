#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

const int maxN = 40, INF = 1e9+7;
vector<int> adj[maxN];
int capacity[maxN][maxN];
int counter;

int bfs(int source, int target, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int,int>> q;
    q.push({source, INF});
    while (!q.empty()) {
        auto [current, flow] = q.front();
        q.pop();

        for (int next: adj[current]) {
            if (parent[next] == -1 && capacity[current][next]) {
                parent[next] = current;
                int adjusted_flow = min(flow, capacity[current][next]);
                if (next == target)
                    return adjusted_flow;
                q.push({next, adjusted_flow});
            }
        }
    }

    return 0;
}

void print_answer() {
    for (int i = 27; i < 37; i++) {
        bool found = false;

        for (int j = 1; j < 27; j++) {
            if (capacity[i][j]) {
                found = true;
                cout << char('A' + j - 1);
                break;
            }
        }

        if (!found) cout << "_";
    }
    cout << endl;
}

void reset() {
    counter = 0;
    for (int i = 0; i < maxN; i++) {
        adj[i].clear();
        for (int j = 0; j < maxN; j++) {
            capacity[i][j] = 0;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        adj[0].push_back(c-'A'+1);
        adj[c-'A'+1].push_back(0);
    }

    for (int i = 27; i < 37; i++) {
        adj[i].push_back(37);
        adj[37].push_back(i);
        capacity[i][37] = 1;
    }
}

int main(void) {
    string input;
    int source = 0;
    int target = 37;

    reset();

    while (true) {
        bool fin = cin.peek() == EOF;
        if (!fin) {
            getline(cin, input);
        }
        if (fin || input == "") {
            if (counter > 10) {
                cout << "!" << endl;
            } else {
                int flow = 0;
                int tmp;
                vector<int> parent(maxN);
                while ((tmp = bfs(source, target, parent))) {
                    flow += tmp;
                    int current = target;
                    while (current != source) {
                        int previous = parent[current];
                        capacity[previous][current] -= tmp;
                        capacity[current][previous] += tmp;
                        current = previous;
                    }
                }

                if (flow != counter) {
                    cout << "!" << endl;
                } else {
                    print_answer();
                }
            }

            if (fin) break;
            reset();
            continue;
        }

        stringstream ss(input);
        char app, tmp;
        int users, x;

        ss >> app >> users;
        counter += users;
        capacity[0][app-'A'+1] = users;

        while (ss >> tmp) {
            if (tmp == ';') break;
            x = tmp - '0';
            adj[app-'A'+1].push_back(27+x);
            adj[27+x].push_back(app-'A'+1);
            capacity[app-'A'+1][27+x] = INF;
        }
    }

    return 0;
}
