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
		int solve(int n, int t);
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

int Graph::solve(int n, int t) {
	int counter = 0;
	bool visited[n+1];
	Vertex* v;

	for (int i = 0; i <= n; i++)
		visited[i] = false;
	
	queue<int> q;
	int tmp;

	tmp = t;
	q.push(tmp);

	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		counter++;

		visited[tmp] = true;
		v = getVertex(tmp);

		for (int i = 0, sz = v->adj.size(); i < sz; i++) {
			if (visited[v->adj[i]->id] == false) {
				visited[v->adj[i]->id] = true;
				q.push(v->adj[i]->id);
			}
		}
	}

	return counter;
}

struct result {
	int task;
	int dep;
	result() : task(0), dep(0) {}
};

int main (void) {
	int n, t, adj;

	while (cin >> n) {
		if (n == 0)
			break;

		Graph g;

		for (int i = 1; i <= n; i++) {
			cin >> t;
			while (t--) {
				cin >> adj;
				g.addEdge(i, adj, true);
			}
		}

		result best;
		for (int i = 1; i <= n; i++) {
			int tmp = g.solve(n, i);
			if (tmp > best.dep) {
				best.task = i;
				best.dep = tmp;
			}
		}
		cout << best.task << endl;
	}

	return 0;
}
