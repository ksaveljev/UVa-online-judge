#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
using namespace std;

typedef char vdata;

struct Vertex 
{
	public:
		vdata id;
		vector<Vertex*> adj;
		map<vdata, int> distances;
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
		void addEdge (vdata begin, vdata end, int distance, bool directed);
		Vertex* firstVertex();
		int traverse();
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

void Graph::addEdge (vdata begin, vdata end, int distance, bool directed = false)
{
	Vertex* v = getVertex (begin);
	Vertex* w = getVertex (end);
	v->adj.push_back (w);
	v->distances[w->id] = distance;
	if (!directed) {
		w->adj.push_back (v);
		w->distances[v->id] = distance;
	}
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

int Graph::traverse()
{
	Vertex* b;
	Vertex* e;
	bool found = false;
	
	for (int i = 0; i < allVertexes.size(); i++) {
		if (allVertexes[i]->adj.size() % 2 > 0) {
			if (!found) {
				found = true;
				b = allVertexes[i];
			} else {
				e = allVertexes[i];
			}	
		}
	}
	
	if (!found) return 0;
	
	
	// here comes Dijkstra
	map<vdata,bool> intree; // is the vertex in the tree yet?
	map<vdata,int> distance; // distance vertex is from start
	int weight, dist;
	Vertex* v;
	Vertex* w;
	
	for (int i = 0; i < allVertexes.size(); i++) {
		intree[allVertexes[i]->id] = false;
		distance[allVertexes[i]->id] = INT_MAX;
	}
	
	distance[b->id] = 0;
	v = b;
	
	while (intree[v->id] == false) {
		intree[v->id] = true;
		
		for (int i = 0; i < v->adj.size(); i++) {
			w = v->adj[i];
			weight = v->distances[w->id];
			if (distance[w->id] > (distance[v->id] + weight)) {
				distance[w->id] = distance[v->id] + weight;
			}
		}
		
		v = b;
		dist = INT_MAX;
		for (int i = 0; i < allVertexes.size(); i++) {
			if (intree[allVertexes[i]->id] == false && dist > distance[allVertexes[i]->id]) {
				dist = distance[allVertexes[i]->id];
				v = allVertexes[i];
			}
		}
	}
	
	return distance[e->id];
}

int main (void) {
	Graph* g = new Graph();
	string input;
	int sum = 0;
	vector<string> streets;
	
	while (cin >> input) {
		if (input == "deadend") {
			for (int i = 0; i < streets.size(); i++) {
				g->addEdge (streets[i][0], streets[i][streets[i].size()-1], streets[i].size());
			}
			
			cout << sum + g->traverse() << endl;
			
			sum = 0;
			streets.clear();
			delete g;
			g = new Graph();
		} else {
			streets.push_back (input);
			sum += input.size();
		}
	}
	
	delete g;
	
	return 0;
}