#include <iostream>
#include <map>
#include <vector>
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
    vector<int> result;
    void solve(int n);
    void visit(int n, bool *visited);
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

void Graph::solve(int n)
{
  Vertex* v;
  bool nodes[n+1];
  bool visited[n+1];

  fill (nodes, nodes + n + 1, true);
  fill (visited, visited + n + 1, false);

  // get all nodes with no incoming edges
  for (int i = 1; i <= n; i++) {
    v = getVertex(i);

    for (int j = 0, sz = v->adj.size(); j < sz; j++) {
      nodes[v->adj[j]->id] = false;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (nodes[i]) {
      visit(i, visited);
    }
  }
}

void Graph::visit(int n, bool *visited)
{
  if (visited[n])
    return;

  visited[n] = true;

  Vertex* v = getVertex(n);

  for (int i = 0, sz = v->adj.size(); i < sz; i++)
    visit(v->adj[i]->id, visited);

  result.push_back(n);
}

int main (void) {
  int n, m;
  int a, b;

  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    Graph g;

    for (int i = 1; i <= n; i++)
      g.addVertex(i);

    while (m--) {
      cin >> a >> b;
      //g.addEdge(a, b, true);
      g.addEdge(b, a, true);
    }

    g.solve(n);

    for (int i = 0; i < n; i++) {
      if (i > 0)
        cout << " ";
      cout << g.result[i];
    }
    cout << endl;
  }

	return 0;
}
