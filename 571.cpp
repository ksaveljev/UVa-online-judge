#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

/*
 * 1: fill A
 * 2: fill B
 * 3: empty A
 * 4: empty B
 * 5: pour A B
 * 6: pour B A
 */
vector<int> result_steps;

typedef struct _state {
    int a, b;
    vector<int> steps;
} state;

void solve(int A, int B, int N) {
    int new_a, new_b;
    map<int, bool> visited;
    visited[0] = true;
    queue<state> q;
    state tmp;

    tmp.a = 0;
    tmp.b = 0;

    q.push(tmp);


    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.b == N) {
            result_steps = tmp.steps;
            break;
        }

        // fill A
        if (visited.find(A * 10000 + tmp.b) == visited.end()) {
            visited[A * 10000 + tmp.b] = true;
            state s(tmp);
            s.a = A;
            s.steps.push_back(1);
            q.push(s);
        }

        // fill B
        if (visited.find(tmp.a * 10000 + B) == visited.end()) {
            visited[tmp.a * 10000 + B] = true;
            state s(tmp);
            s.b = B;
            s.steps.push_back(2);
            q.push(s);
        }

        // empty A
        if (visited.find(tmp.b) == visited.end()) {
            visited[tmp.b] = true;
            state s(tmp);
            s.a = 0;
            s.steps.push_back(3);
            q.push(s);
        }

        // empty B
        if (visited.find(tmp.a * 10000) == visited.end()) {
            visited[tmp.a * 10000] = true;
            state s(tmp);
            s.b = 0;
            s.steps.push_back(4);
            q.push(s);
        }

        // pour A B
        new_a = max(tmp.a - (B - tmp.b), 0);
        new_b = tmp.b + tmp.a - new_a;
        if (visited.find(new_a * 10000 + new_b) == visited.end()) {
            visited[new_a * 10000 + new_b] = true;
            state s(tmp);
            s.a = new_a;
            s.b = new_b;
            s.steps.push_back(5);
            q.push(s);
        }

        // pour B A
        new_b = max(tmp.b - (A - tmp.a), 0);
        new_a = tmp.a + tmp.b - new_b;
        if (visited.find(new_a * 10000 + new_b) == visited.end()) {
            visited[new_a * 10000 + new_b] = true;
            state s(tmp);
            s.a = new_a;
            s.b = new_b;
            s.steps.push_back(6);
            q.push(s);
        }
    }
}

int main(void) {
    string steps[] = {
        "",
        "fill A",
        "fill B",
        "empty A",
        "empty B",
        "pour A B",
        "pour B A"
    };
    int A, B, N;

    while (cin >> A >> B >> N) {
        solve(A, B, N);

        rep (i, result_steps.size()) {
            cout << steps[result_steps[i]] << endl;
        }
        cout << "success" << endl;
    }

    return 0;
}
