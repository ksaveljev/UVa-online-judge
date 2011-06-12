#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef char vdata;

struct Vertex 
{
	public:
		vdata id;
    bool waken;
		vector<Vertex*> adj;
		Vertex (vdata id) : id(id), waken(false) {}
};

typedef map<vdata, Vertex*> vmap;
typedef pair<vdata, Vertex*> vpair;

class Graph 
{
	public:
		Graph() {}
		~Graph();
		Vertex* addVertex (vdata v, bool waken);
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

Vertex* Graph::addVertex (vdata v, bool waken = false) {
	Vertex* newv = new Vertex (v);
  newv->waken = waken;
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

int Graph::solve(int n) {
  int result = 0;
  int counter;
  vector<Vertex*> wakeup;

  //cout << "allVertexes.size() = " << allVertexes.size() << endl;
  //cout << "n = " << n << endl;
  if (allVertexes.size() != n)
    return -1;

  while (true) {
    for (int i = 0, sz = allVertexes.size(); i < sz; i++) {
      if (allVertexes[i]->waken) continue;

      counter = 0;
      for (int j = 0, sz2 = allVertexes[i]->adj.size(); j < sz2; j++) {
        if (allVertexes[i]->adj[j]->waken)
          counter++;
      }

      if (counter > 2)
        wakeup.push_back(allVertexes[i]);
    }

    if (wakeup.empty())
      break;

    for (int i = 0, sz = wakeup.size(); i < sz; i++)
      wakeup[i]->waken = true;

    result++;

    wakeup.clear();
  }

  for (int i = 0, sz = allVertexes.size(); i < sz; i++)
    if (allVertexes[i]->waken == false)
      return -1;

  return result;
}

int main (void) {
  int n, m;
  char c1, c2;

  while (cin >> n >> m) {
    Graph g;

    //cout << "n = " << n << endl;
    //cout << "m = " << m << endl;

    for (int i = 0; i < 3; i++) {
      cin >> c1;
      g.addVertex(c1, true);
    }

    while (m--) {
      cin >> c1 >> c2;
      g.addEdge(c1, c2);
    }

    int result = g.solve(n);
    if (result == -1) {
      cout << "THIS BRAIN NEVER WAKES UP" << endl;
    } else {
      cout << "WAKE UP IN, " << result << ", YEARS" << endl;
    }
  }

	return 0;
}
