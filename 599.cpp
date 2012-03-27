#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <sstream>
#include <queue>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

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
        void solve();
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

void Graph::solve()
{
    int trees = 0, acorn = 0;
    map<vdata,bool> visited;

    rep (i, allVertexes.size()) {
        if (visited.find(allVertexes[i]->id) != visited.end())
            continue;

        queue<Vertex*> q;
        Vertex *tmp;

        q.push(allVertexes[i]);
        visited[allVertexes[i]->id] = true;

        int size = 1;

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            rep (j, tmp->adj.size()) {
                if (visited.find(tmp->adj[j]->id) != visited.end())
                    continue;

                size++;
                q.push(tmp->adj[j]);
                visited[tmp->adj[j]->id] = true;
            }
        }

        if (size > 1)
            trees++;
        else
            acorn++;
    }

    cout << "There are " << trees << " tree(s) and " << acorn << " acorn(s)." << endl;
}

int main (void) {
    int t;
    char a, b, tmp;
    string input;

    cin >> t;

    while (t--) {
        Graph g;

        while (cin >> tmp) {
            if (tmp == '*') {
                cin.ignore(100, '\n');
                break;
            }

            cin >> a >> tmp >> b >> tmp;
            g.addEdge(a, b);
        }


        getline(cin, input);

        rep (i, input.size())
            if (input[i] == ',')
                input[i] = ' ';

        istringstream iss(input);

        vector<char> v;
        copy (istream_iterator<char>(iss), istream_iterator<char>(), back_inserter(v));

        rep (i, v.size())
            g.addVertex(v[i]);

        g.solve();
    }

	return 0;
}
