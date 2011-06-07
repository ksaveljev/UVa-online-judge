#include <iostream>
#include <map>
#include <vector>
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
    int solve();
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

int Graph::solve() {
  Vertex *v;
  int tmp;
  queue<int> q;
  int result = 0;
  bool visited[allVertexes.size()+1];

  fill(visited, visited + allVertexes.size()+1, false);

  for (int i = 0, sz = allVertexes.size(); i < sz; i++) {
    v = allVertexes[i];
    if (visited[v->id] == true) continue;

    result++;

    q.push(v->id);
    visited[v->id] = true;

    while (!q.empty()) {
      tmp = q.front();
      q.pop();

      v = getVertex(tmp);

      for (int j = 0, sz2 = v->adj.size(); j < sz2; j++) {
        if (visited[v->adj[j]->id] == true) continue;

        visited[v->adj[j]->id] = true;
        q.push(v->adj[j]->id);
      }
    }
  }

  return result;
}

int main (void) {
  int n, m;
  int a, b;
  int counter = 0;

  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    counter++;

    Graph g;

    for (int i = 1; i <= n; i++)
      g.addVertex(i);

    while (m--) {
      cin >> a >> b;
      g.addEdge(a, b);
    }

    cout << "Case " << counter << ": " << g.solve() << endl;
  }

	return 0;
}
