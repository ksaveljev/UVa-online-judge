#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

typedef pair<double,double> vdata;

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
    int solve(const pair<double,double> &start, const pair<double,double> &end, int speed, int time);
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

double between(const pair<double,double> &a, const pair<double,double> &b) {
  return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); 
}

int Graph::solve(const pair<double,double> &start, const pair<double,double> &end, int speed, int time) {
  Vertex* v;
  map< pair<double,double>, bool > visited;
  double distance = speed * time * 60.0;
  pair< pair<double,double>, int > tmp;
  queue< pair< pair<double,double>, int> > q;

  tmp.first = start;
  tmp.second = 0;
  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first == end)
      return tmp.second - 1;

    v = getVertex(tmp.first);

    for (int i = 0, sz = v->adj.size(); i < sz; i++) {
      if (visited.find(v->adj[i]->id) != visited.end())
        continue;

      if (between(v->adj[i]->id, tmp.first) > distance)
        continue;

      q.push(make_pair(v->adj[i]->id, tmp.second+1));
      visited[v->adj[i]->id] = true;
    }
  }

  return -1;
}

int main (void) {
  int speed, time;
  pair<double,double> start, end;
  pair<double,double> tmp;
  vector< pair<double,double> > holes;

  while (cin >> speed >> time) {
    if (speed == 0 && time == 0)
      break;

    Graph g;
    holes.clear();

    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    cin.ignore(100,'\n');

    g.addEdge(start, end);
    holes.push_back(start);
    holes.push_back(end);

    while (cin.peek() != '\n') {
      cin >> tmp.first >> tmp.second;

      for (int i = 0, sz = holes.size(); i < sz; i++) {
        g.addEdge(tmp, holes[i]);
      }

      holes.push_back(tmp);
      cin.ignore(100, '\n');
    }

    int result = g.solve(start, end, speed, time);

    if (result == -1)
      cout << "No." << endl;
    else
      cout << "Yes, visiting " << result << " other holes." << endl;
  }

	return 0;
}
