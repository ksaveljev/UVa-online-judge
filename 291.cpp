#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool visited[100];
vector<int> steps;
set<int> results;
vector<int> r;

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
		void solve(int point, int depth);
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

void Graph::solve(int point, int depth)
{
	if (depth == 8) {
		int result = 0;
		for (int i = 0, sz = steps.size(); i < sz; i++) {
			result = result * 10 + steps[i];
		}
		
		results.insert(result);

		return;
	}

	Vertex* v = getVertex(point);
	for (int i = 0, sz = v->adj.size(); i < sz; i++) {
		if (visited[point*10 + v->adj[i]->id] == false) {
			visited[point*10 + v->adj[i]->id] = true;
			visited[v->adj[i]->id * 10 + point] = true;
			steps.push_back(v->adj[i]->id);
			solve(v->adj[i]->id, depth+1);
			steps.pop_back();
			visited[v->adj[i]->id * 10 + point] = false;
			visited[point*10 + v->adj[i]->id] = false;
		}
	}
}

int main (void) {
	Graph g;

	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 5);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	for (int i = 0; i < 100; i++)
		visited[i] = false;

	steps.push_back(1);
	g.solve(1, 0);

	for (set<int>::iterator it = results.begin(); it != results.end(); it++) {
		r.push_back(*it);
	}

	sort(r.begin(), r.end());

	for (int i = 0, sz = r.size(); i < sz; i++)
		cout << r[i] << endl;

	return 0;
}
