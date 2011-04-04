#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

bool visited[2501];
map<int,int> stats;

class Graph 
{
	public:
		Graph() {}
		~Graph();
		Vertex* addVertex (vdata v);
		void addEdge (vdata begin, vdata end, bool directed);
		Vertex* firstVertex();
		void solve(int source, int day);
	//private:
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

void Graph::solve(int source, int day)
{
	pair<int,int> p;
	queue< pair<int, int> > q;
	q.push(make_pair(source, day));

	visited[source] = true;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		Vertex* v = getVertex(p.first);
		for (int i = 0, sz = v->adj.size(); i < sz; i++) {
			if (visited[v->adj[i]->id] == false) {
				visited[v->adj[i]->id] = true;
				q.push(make_pair(v->adj[i]->id, p.second+1));
				if (stats.find(p.second+1) == stats.end()) {
					stats[p.second+1] = 1;
				} else {
					stats[p.second+1] += 1;
				}
			}
		}
	}
}

int main (void) {
	int e, n, f, t, source;
	Graph g;

	cin >> e;

	for (int i = 0; i < e; i++) {
		cin >> n;
		while (n--) {
			cin >> f;
			g.addEdge(i, f, true);
		}
	}

	cin >> t;

	while (t--) {
		for (int i = 0; i < 2501; i++)
			visited[i] = false;

		stats.clear();

		cin >> source;
		g.solve(source, 0);
		
		if (stats.find(1) == stats.end()) {
			cout << 0 << endl;
		} else {
			int best = -1;
			int bestday = -1;
			for (int i = 1; i < 100000; i++) {
				if (stats.find(i) == stats.end())
					break;

				if (stats[i] > best) {
					best = stats[i];
					bestday = i;
				}
			}

			cout << best << " " << bestday << endl;
		}
	}

	return 0;
}
