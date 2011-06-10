#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef int vdata;

struct Vertex 
{
  public:
    vdata id;
    vector<Vertex*> adj;
    Vertex (vdata id) : id(id) {}
};

typedef map<vdata, Vertex*> vmap;
typedef pair<vdata, Vertex*> vpair;

class Graph 
{
  public:
    Graph() {}
    ~Graph();
    Vertex* addVertex (vdata v);
    void addEdge (vdata begin, vdata end, bool directed);
    Vertex* firstVertex();
    int solve(int n);
  private:
    Vertex* getVertex (vdata v);
    vmap vertexMap;
    vector<Vertex*> allVertexes;
};

Graph::~Graph()
{
  for (int i = 0; i < allVertexes.size(); i++)
    delete allVertexes[i];
}

Vertex* Graph::addVertex (vdata v) {
  Vertex* newv = new Vertex (v);
  allVertexes.push_back (newv);
  vertexMap.insert (vpair (v, newv));
  return newv;
}

void Graph::addEdge (vdata begin, vdata end, bool directed = false)
{
  Vertex* v = getVertex (begin);
  Vertex* w = getVertex (end);
  v->adj.push_back (w);
  if (!directed)
    w->adj.push_back (v);
}

Vertex* Graph::getVertex (vdata v)
{
  vmap::iterator it = vertexMap.find (v);

  if (it == vertexMap.end()) {
    return addVertex (v);
  }

  return (*it).second;
}

Vertex* Graph::firstVertex()
{
  return allVertexes[0];
}

int Graph::solve(int n)
{
  int tmp;
  queue<int> q;
  Vertex* v;
  bool visited[n+1];
  int result = 0;

  fill (visited, visited + n + 1, false);

  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;

    result++;

    q.push(i);
    visited[i] = true;

    while (!q.empty()) {
      tmp = q.front();
      q.pop();

      v = getVertex(tmp);

      for (int j = 0, sz = v->adj.size(); j < sz; j++) {
        if (visited[v->adj[j]->id]) continue;

        visited[v->adj[j]->id] = true;
        q.push(v->adj[j]->id);
      }
    }
  }

  return result;
}

int main (void) {
  int t, n;
  double d;
  double x, y;
  vector< pair<double,double> > stars;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    Graph g;

    stars.clear();
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
      g.addVertex(i);
      cin >> x >> y;
      for (int j = 0, sz = stars.size(); j < sz; j++) {
        double dist = sqrt((x-stars[j].first)*(x-stars[j].first)+(y-stars[j].second)*(y-stars[j].second));
        if (dist <= d) {
          g.addEdge(i, j);
        }
      }
      stars.push_back(make_pair(x,y));
    }

    cout << "Case " << casenum+1 << ": " << g.solve(n) << endl;
  }

  return 0;
}
