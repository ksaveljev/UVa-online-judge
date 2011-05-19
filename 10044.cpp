#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

map<string,int> result;

typedef string vdata;

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
    void calculate();
		Vertex* addVertex (vdata v);
		void addEdge (vdata begin, vdata end, bool directed);
		Vertex* firstVertex();
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

void Graph::calculate()
{
  map<string,bool> visited;
  pair<string,int> tmp;
  queue< pair<string,int> > q;

  string initial = "Erdos, P.";

  visited[initial] = true;
  Vertex *v = getVertex(initial);

  tmp.first = initial;
  tmp.second = 0;

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    v = getVertex(tmp.first);

    for (int i = 0, sz = v->adj.size(); i < sz; i++) {
      if (visited.find(v->adj[i]->id) != visited.end())
        continue;

      if (result.find(v->adj[i]->id) == result.end()) {
        result[v->adj[i]->id] = tmp.second + 1;
      } else {
        result[v->adj[i]->id] = min(result[v->adj[i]->id], tmp.second + 1);
      }
      visited[v->adj[i]->id] = true;
      q.push(make_pair(v->adj[i]->id, tmp.second + 1));
    }
  }
}

void scan_for_names(const string &s, Graph &g) {
  string name;
  bool first = false;
  vector<string> names;

  for (int i = 0, sz = s.size(); i < sz; i++) {
    if (s[i] == ':') {
      if (first) {
        g.addVertex(name);
        names.push_back(name);
      }
      break;
    } else if (s[i] == ',') {
      if (!first) {
        name += s[i];
        first = true;
      } else {
        first = false;
        g.addVertex(name);
        names.push_back(name);
        name = "";
      }
    } else {
      if (!first && s[i] == ' ')
        continue;
      name += s[i];
    }
  }

  for (int i = 0, sz = names.size(); i < sz - 1; i++) {
    for (int j = 1; j < sz; j++) {
      g.addEdge(names[i], names[j]);
    }
  }
}

int main (void) {
  int t, p, n;
  string input;

  cin >> t;

  for (int scenario = 0; scenario < t; scenario++) {
    Graph g;

    result.clear();

    cin >> p >> n;
    cin.ignore(100, '\n');

    while (p--) {
      getline(cin, input);
      scan_for_names(input, g);
    }

    g.calculate();

    cout << "Scenario " << scenario+1 << endl;
    while (n--) {
      getline(cin, input);
      if (result.find(input) == result.end())
        cout << input << " infinity" << endl;
      else
        cout << input << " " << result[input] << endl;
    }
  }

	return 0;
}
