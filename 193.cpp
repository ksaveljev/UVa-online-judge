#include <iostream>
#include <map>
#include <vector>
using namespace std;

int maximum = 0;
int colored = 0;
int vertices;
vector<int> best;
vector<int> taken;

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
		Vertex* addVertex (int v);
		void addEdge (int begin, int end, bool directed);
		Vertex* firstVertex();
		void applyColors(int n);
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

Vertex* Graph::addVertex (int v) {
	Vertex* newv = new Vertex (v);
	allVertexes.push_back (newv);
	vertexMap.insert (vpair (v, newv));
	return newv;
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
		return addVertex (v);
	}
	
	return (*it).second;
}

Vertex* Graph::firstVertex()
{
	return allVertexes[0];
}

void Graph::applyColors(int n)
{
	if (n == allVertexes.size()) {
		if (colored > maximum) {
			maximum = colored;
			best.clear();
			for (int i = 0; i < taken.size(); i++)
				best.push_back(taken[i]);
		}
	} else {
		allVertexes[n]->color = 0;
		colored += 1;
		taken.push_back(allVertexes[n]->id);
		
		bool good = true;
		for (int i = 0; i < allVertexes[n]->adj.size(); i++)
			if (allVertexes[n]->adj[i]->color == 0) {
				good = false;
				break;
			}

		if (good)
			applyColors (n+1);

		colored -= 1;
		taken.pop_back();

		allVertexes[n]->color = 1;
		
		applyColors (n+1);
	}
}


int main (void) {
	int n, v, e, a, b;
	
	cin >> n;
	
	while (n--) {
		best.clear();
		taken.clear();
		maximum = 0;
		colored = 0;
		
		Graph* g = new Graph();
		cin >> v >> e;
		vertices = v;
		
		for (int i = 1; i <= v; i++)
			g->addVertex (i);
		
		while (e--) {
			cin >> a >> b;
			g->addEdge(a,b);
		}
		
		g->applyColors(0);
		
		cout << maximum << endl;
		for (int i = 0; i < best.size(); i++) {
			if (i > 0) cout << " ";
			cout << best[i];
		}
		cout << endl;
		
		delete g;
	}
	
	return 0;
}