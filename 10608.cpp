#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
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

int Graph::solve (int n) {
  int best = 0, result;
  queue<int> q;
  int tmp;
  Vertex *v;
  bool visited[n+1];

  fill(visited, visited+n+1, false);

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;

    q.push(i);
    visited[i] = true;
    result = 1;

    while (!q.empty()) {
      tmp = q.front();
      q.pop();

      v = getVertex(tmp);

      for (int j = 0, sz = v->adj.size(); j < sz; j++) {
        if (visited[v->adj[j]->id] == true) continue;

        visited[v->adj[j]->id] = true;
        q.push(v->adj[j]->id);
        result++;
      }
    }

    if (result > best)
      best = result;
  }

  return best;
}

int main (void) {
  int t;
  int n, m;
  int a, b;

  cin >> t;

  while (t--) {
    cin >> n >> m;

    Graph g;

    for (int i = 1; i <= n; i++)
      g.addVertex(i);

    while (m--) {
      cin >> a >> b;
      g.addEdge(a, b);
    }

    cout << g.solve(n) << endl;
  }

	return 0;
}
