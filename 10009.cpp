#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef char vdata;

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
		string solve(char start, char end);
	private:
		Vertex* getVertex (vdata v);
		vmap vertexMap;
		vector<Vertex*> allVertexes;
		map<char,bool> visited;
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

string Graph::solve(char start, char end) {
	pair<Vertex*, string> tmp;
	queue< pair<Vertex*, string> > q;

	string s = "";
	s += start;

	visited[getVertex(start)->id] = true;
	q.push( make_pair(getVertex(start), s) );

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		if (tmp.first->id == end) {
			visited.clear();
			return tmp.second;
		}

		for (int i = 0, sz = tmp.first->adj.size(); i < sz; i++) {
			if (visited.find(tmp.first->adj[i]->id) == visited.end()) {
				q.push(make_pair(tmp.first->adj[i], tmp.second + tmp.first->adj[i]->id));
				visited[tmp.first->adj[i]->id] = true;
			}
		}
	}
}

int main (void) {
	int cases, m, n;
	string city1, city2;

	cin >> cases;

	while (cases--) {
		cin >> m >> n;

		Graph g;

		while (m--) {
			cin >> city1 >> city2;
			g.addEdge(city1[0], city2[0]);
		}

		while (n--) {
			cin >> city1 >> city2;
			cout << g.solve(city1[0], city2[0]) << endl;
		}

		if (cases)
			cout << endl;
	}

	return 0;
}
