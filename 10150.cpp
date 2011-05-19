#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

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
    void bfs(const vdata &a, const vdata &b);
		Vertex* addVertex (vdata v);
		void addEdge (vdata begin, vdata end, bool directed);
		Vertex* firstVertex();
	private:
		Vertex* getVertex (const vdata &v);
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

Vertex* Graph::getVertex (const vdata &v)
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

void Graph::bfs(const string &a, const string &b) {
  Vertex *v;
  map<string,bool> visited;
  pair<string,string> tmp;
  queue< pair<string,string> > q;

  q.push(make_pair(a, a + "\n"));

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    v = getVertex(tmp.first);
    for (int i = 0, sz = v->adj.size(); i < sz; i++) {
      if (visited.find(v->adj[i]->id) != visited.end())
        continue;

      if (v->adj[i]->id == b) {
        cout << tmp.second << b << endl;
        return;
      }

      visited[v->adj[i]->id] = true;
      q.push(make_pair(v->adj[i]->id, tmp.second + v->adj[i]->id + "\n"));
    }
  }

  cout << "No solution." << endl;
}

bool is_doublet(const string &a, const string &b) {
  int diff = 0;

  for (int i = 0, sz = a.size(); i < sz; i++) {
    if (a[i] != b[i]) {
      diff++;

      if (diff > 1)
        return false;
    }
  }

  return true;
}

int main (void) {
  int len;
  bool first = true;
  Graph g;
  vector<string> words[17];
  string input, a, b;

  while (getline(cin ,input)) {
    if (input == "")
      break;

    len = input.size();
    for (int i = 0, sz = words[len].size(); i < sz; i++) {
      if (!is_doublet(input, words[len][i]))
        continue;

      g.addEdge(input, words[len][i]);
    }

    words[len].push_back(input);
  }

  while (cin >> a >> b) {
    if (!first)
      cout << endl;

    g.bfs(a, b);

    first = false;
  }
  
	return 0;
}
