#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Vertex 
{
	public:
		int id;
		int color;
		vector<Vertex*> adj;
		Vertex (int id) : id(id) { color = -1; }
};

typedef map<int, Vertex*> vmap;
typedef pair<int, Vertex*> vpair;

class Graph 
{
	public:
		Graph() {}
		~Graph();
		void addEdge (int begin, int end, bool directed);
		bool bicolor(Vertex* v, int color);
		Vertex* firstVertex();
	private:
		Vertex* getVertex (int v);
		vmap vertexMap;
		vector<Vertex*> allVertexes;
};

Graph::~Graph()
{
	for (int i = 0; i < allVertexes.size(); i++)
		delete allVertexes[i];
}

void Graph::addEdge (int begin, int end, bool directed = false)
{
	Vertex* v = getVertex (begin);
	Vertex* w = getVertex (end);
	v->adj.push_back (w);
	if (!directed)
		w->adj.push_back (v);
}

Vertex* Graph::getVertex (int v)
{
	vmap::iterator it = vertexMap.find (v);
	
	if (it == vertexMap.end()) {
		Vertex* newv = new Vertex (v);
		allVertexes.push_back (newv);
		vertexMap.insert (vpair (v, newv));
		return newv;
	}
	
	return (*it).second;
}

Vertex* Graph::firstVertex()
{
	return allVertexes[0];
}

bool Graph::bicolor(Vertex* v, int color)
{
	bool result = true;
	
	if (v->color == -1) {
		v->color = color;
		for (int i = 0; i < v->adj.size(); i++) {
			result = bicolor(v->adj[i], (color + 1) % 2);
			if (!result) break;
		}
	} else {
		if (v->color != color)
			result = false;
	}
	
	return result;
}

int main (void) {
	int nodes, edges, a, b;
	
	while (cin >> nodes) {
		if (nodes == 0) break;
		cin >> edges;
		
		Graph* g = new Graph();
		while (edges--) {
			cin >> a >> b;
			g->addEdge (a,b);
		}
		
		if (g->bicolor(g->firstVertex(), 0))
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
		
		delete g;
	}
}