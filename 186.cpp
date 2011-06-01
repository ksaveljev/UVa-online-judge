#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int INF = 1000000000;
int dist[150][150];
int p[150][150];
int n = 0;
vector<int> path;

void construct_path(int a, int b) {
  if (a != b) {
    construct_path(a, p[a][b]);
  }
  path.push_back(b);
}

int main(void) {
  string a, b, route;
  int d;
  map<string,int> cities;
  map<int,string> m;
  map< pair<int,int>,pair<string,int> > routes;

  for (int i = 0; i < 150; i++) {
    for (int j = 0; j < 150; j++) {
      dist[i][j] = INF;
      p[i][j] = i;
    }
  }

  while (cin.peek() != '\n') {
    getline(cin, a, ',');
    if (cities.find(a) == cities.end()) {
      cities[a] = n;
      m[n] = a;
      n++;
    }
    getline(cin, b, ',');
    if (cities.find(b) == cities.end()) {
      cities[b] = n;
      m[n] = b;
      n++;
    }
    getline(cin, route, ',');

    cin >> d;
    cin.ignore(100, '\n');

    routes.insert(make_pair(make_pair(cities[a], cities[b]), make_pair(route, d)));
    routes.insert(make_pair(make_pair(cities[b], cities[a]), make_pair(route, d)));
    dist[cities[a]][cities[b]] = min(dist[cities[a]][cities[b]], d);
    dist[cities[b]][cities[a]] = min(dist[cities[a]][cities[b]], d);
  }

  for (int i = 0; i < n; i++)
    dist[i][i] = 0;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          p[i][j] = p[k][j];
        }
      }
    }
  }

  getline(cin, a); // empty line

  while (getline(cin, a, ',')) {
    getline(cin, b);

    path.clear();

    construct_path(cities[a], cities[b]);

    cout << endl << endl; // two blank lines before each report
    cout << "From                 To                   Route      Miles" << endl;
    cout << "-------------------- -------------------- ---------- -----" << endl;

    for (int i = 1, sz = path.size(); i < sz; i++) {
      typeof(routes.begin()) it;
      it = routes.find(make_pair(path[i-1], path[i]));
      string city1 = m[path[i-1]];
      string city2 = m[path[i]];
      printf("%-20s %-20s %-10s %5d\n", city1.c_str(), city2.c_str(), it->second.first.c_str(), it->second.second);
    }

    cout << "                                                     -----" << endl;
    printf("                                          Total      %5d\n", dist[cities[a]][cities[b]]);
  }

  return 0;
}
