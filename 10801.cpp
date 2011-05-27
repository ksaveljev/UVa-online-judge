#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <sstream>
using namespace std;

unsigned int INF = 4000000000;

typedef int vdata;

struct Vertex {
  vdata id;
  vector< pair<Vertex*, int> > adj;
  Vertex (vdata id) : id(id) {}
};

typedef map<vdata, Vertex*> vmap;
typedef pair<vdata, Vertex*> vpair;


class WGraph {
  public:
    WGraph() {}
    ~WGraph();
    Vertex* addVertex (vdata v);
    void addEdge (vdata begin, vdata end, int weight, bool directed);
    Vertex* getVertex (vdata v);
    map<vdata, unsigned int> dijkstra(vdata begin);
  private:
    vmap vertexMap;
    vmap::iterator it;
    vector<Vertex*> allVertexes;
};

WGraph::~WGraph() {
  for (int i = 0, sz = allVertexes.size(); i < sz; i++)
    delete allVertexes[i];
}

Vertex* WGraph::addVertex (vdata v) {
  Vertex* newv = new Vertex (v);
  allVertexes.push_back (newv);
  vertexMap.insert (vpair (v, newv));
  return newv;
}

Vertex* WGraph::getVertex (vdata v) {
  it = vertexMap.find (v);

  if (it == vertexMap.end())
    return addVertex (v);

  return it->second;
}

void WGraph::addEdge (vdata begin, vdata end, int weight, bool directed = false) {
  Vertex* a = getVertex (begin);
  Vertex* b = getVertex (end);
  a->adj.push_back (make_pair (b, weight));
  if (!directed)
    b->adj.push_back (make_pair (a, weight));
}

map<vdata,unsigned int> WGraph::dijkstra(vdata begin) {
  set< pair<int,vdata> > q;
  map<vdata,unsigned int> dist;

  for (int i = 0, sz = allVertexes.size(); i < sz; i++) {
    dist[allVertexes[i]->id] = INF;
  }
  
  dist[begin] = 0;
  q.insert(make_pair(dist[begin], begin));
  while (!q.empty()) {
    vdata v = q.begin()->second;
    q.erase(q.begin());

    Vertex* node = getVertex(v);

    for (int i = 0, sz = node->adj.size(); i < sz; i++) {
      vdata to = node->adj[i].first->id;
      unsigned int len = node->adj[i].second;

      if (dist[v] + len < dist[to]) {
        q.erase(make_pair(dist[to], to));
        dist[to] = dist[v] + len;
        q.insert(make_pair(dist[to], to));
      }
    }
  }

  return dist;
}

void splitstr(const string &input, vector<int> &v) {
  stringstream in(input);
  v.clear();
  copy(istream_iterator<int>(in), istream_iterator<int>(), back_inserter(v));
}

int main(void) {
  int n, k;
  int t[5];
  string input;
  vector<int> floors[5];
  vector<int> v[100];

  while (cin >> n >> k) {
    WGraph g;

    for (int i = 0; i < n; i++)
      cin >> t[i];

    cin.ignore(100, '\n');

    for (int i = 0; i < n; i++) {
      getline(cin, input);
      splitstr(input, floors[i]);
    }

    int start = -1;

    for (int i = 0; i < n; i++) {
      for (int j = 0, sz = floors[i].size(); j < sz; j++) {
        g.addVertex(10000 * i + floors[i][j]);

        if (j > 0) {
          g.addEdge(10000 * i + floors[i][j-1], 10000 * i + floors[i][j], t[i] * (floors[i][j] - floors[i][j-1]));
        }

        if (start == -1 && floors[i][j] == 0) {
          start = i * 10000;
        }

        for (int a = 0, sz2 = v[floors[i][j]].size(); a < sz2; a++) {
          if (floors[i][j] == 0) {
            g.addEdge(v[floors[i][j]][a], 10000 * i + floors[i][j], 0);
          } else {
            g.addEdge(v[floors[i][j]][a], 10000 * i + floors[i][j], 60);
          }
        }

        v[floors[i][j]].push_back(10000 * i + floors[i][j]);
      }
    }

    unsigned int result = INF;
    map<vdata,unsigned int> m = g.dijkstra(start);

    for (int i = 0; i < n; i++) {
      if (m.find(i*10000 +k) != m.end())
        result = min(result, m[i*10000 + k]);
    }

    if (result == INF) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
