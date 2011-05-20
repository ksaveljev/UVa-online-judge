#include <iostream>
#include <map>
#include <vector>
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
    void solve();
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

map<int,int> result;

void Graph::solve() {
  Vertex* v;
  pair<int,int> tmp;
  queue< pair<int,int> > q;
  map<int,bool> visited;

  tmp.first = 0;
  tmp.second = 0;
  q.push(tmp);

  visited[0] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    result[tmp.first] = tmp.second;

    v = getVertex(tmp.first);

    for (int i = 0, sz = v->adj.size(); i < sz; i++) {
      if (visited.find(v->adj[i]->id) != visited.end())
        continue;

      visited[v->adj[i]->id] = true;
      q.push(make_pair(v->adj[i]->id, tmp.second + 1));
    }
  }
}

int main (void) {
  int cases;
  int a, b;
  int p, d;

  cin >> cases;
  
  while (cases--) {
    Graph g;
    result.clear();

    cin >> p >> d;

    while (d--) {
      cin >> a >> b;
      g.addEdge(a, b);
    }

    g.solve();

    for (int i = 1; i < p; i++) {
      cout << result[i] << endl;
    }

    if (cases)
      cout << endl;
  }

	return 0;
}
