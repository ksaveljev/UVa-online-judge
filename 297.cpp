#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef int vdata;

struct Vertex 
{
	public:
        int color;
		vdata id;
		vector<Vertex*> adj;
		Vertex (vdata id) : id(id), color(0) {}
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
        int count_nodes(int color);
        int decode(string &input, int start, int root);
        void color_nodes(int root, int color);
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

int Graph::count_nodes(int color) {
    int result = 0;

    rep (i, allVertexes.size()) {
        if (allVertexes[i]->color == color)
            result++;
    }

    return result;
}

int Graph::decode(string &input, int start, int root) {
    Vertex* v = getVertex(root);
    int offset = start + 1;

    if (input[start] == 'p') {
        rep (i, 4) {
            offset += decode(input, offset, v->adj[i]->id);
        }
    } else {
        color_nodes(v->id, (input[start] == 'e' ? 0 : 1));
    }

    return offset - start;
}

void Graph::color_nodes(int root, int color) {
    Vertex* v = getVertex(root);

    if (v->adj.empty()) {
        v->color = max(v->color, color);
    } else {
        rep (i, 4) {
            color_nodes(v->adj[i]->id, color);
        }
    }
}

int main (void) {
    int n;
    string input;

    cin >> n;
    cin.ignore(100, '\n');

    while (getline(cin, input)) {
        Graph g;

        queue< pair<int,int> > q;
        pair<int,int> tmp;

        q.push(make_pair(1, 0));
        int counter = 1;

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            rep (i, 4) {
                counter++;
                g.addEdge(tmp.first, counter, true);
                if (tmp.second + 1 < 5)
                    q.push(make_pair(counter, tmp.second+1));
            }
        }

        g.decode(input, 0, 1);

        getline(cin, input);

        g.decode(input, 0, 1);

        cout << "There are " << g.count_nodes(1) << " black pixels." << endl;
    }

	return 0;
}
