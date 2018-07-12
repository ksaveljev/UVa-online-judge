#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef struct planet_ {
    char name;
    int value;
    string connections;
} planet;

planet find_planet(char name, const vector<planet>& planets) {
    planet p;

    for (int i = 0, sz = planets.size(); i < sz; i++) {
        if (planets[i].name == name) {
            p = planets[i];
            break;
        }
    }

    return p;
}

double find_cost(const vector<planet>& planets, int idx) {
    set<char> visited;
    queue< pair<char, double> > q;

    q.push(make_pair(planets[idx].name, planets[idx].value));
    visited.insert(planets[idx].name);

    while (!q.empty()) {
        pair<char, double> current = q.front();
        q.pop();

        planet p = find_planet(current.first, planets);

        for (int i = 0, sz = p.connections.size(); i < sz; i++) {
            if (p.connections[i] == '*') {
                return current.second;
            } else if (visited.find(p.connections[i]) == visited.end()) {
                q.push(make_pair(p.connections[i], current.second * 0.95));
                visited.insert(p.connections[i]);
            }
        }
    }

    return -1;
}

int main(void) {
    int n, l;
    char h, tmp;
    string connections;
    double epsilon = 0.00000001;

    while (cin >> n) {
        vector<planet> planets;

        for (int i = 0; i < n; i++) {
            planet p;
            cin >> p.name >> h >> tmp >> l >> p.connections;
            p.value = (h - '0') * 100 + l;
            planets.push_back(p);
        }

        double best_cost = -1;
        char best_name = ' ';

        for (int i = 0; i < n; i++) {
            double cost = find_cost(planets, i);
            if (cost > best_cost) {
                best_cost = cost;
                best_name = planets[i].name;
            } else if (fabs(best_cost - cost) < epsilon && planets[i].name < best_name) {
                best_name = planets[i].name;
            }
        }

        cout << "Import from " << best_name << endl;
    }

    return 0;
}
