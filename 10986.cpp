#include <iostream>
#include <map>
#include <vector>
#include <set>
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
    unsigned int dijkstra(vdata begin, vdata end);
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

unsigned int WGraph::dijkstra(vdata begin, vdata end) {
  set< pair<int,vdata> > q;
  map<vdata,int> dist;

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

  return dist[end];
}

int main(void) {
  int cases;
  int n, m, s, t;
  int a, b, w;

  cin >> cases;

  for (int casenum = 0; casenum < cases; casenum++) {
    WGraph g;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < n; i++)
      g.addVertex(i);

    for (int i = 0; i < m; i++) {
      cin >> a >> b >> w;
      g.addEdge(a, b, w);
    }

    cout << "Case #" << casenum+1 << ": ";
    unsigned int result = g.dijkstra(s, t);
    if (result == INF) {
      cout << "unreachable" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
