#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

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
        bool isTree(int edges_count);
	private:
		Vertex* getVertex (vdata v);
		vmap vertexMap;
		vector<Vertex*> allVertexes;
        int countConnectedNodes(vdata root);
        vdata findRootNode();
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

vdata Graph::findRootNode()
{
    vdata root = -1;
    map<vdata,bool> m;

    rep (i, allVertexes.size()) {
        rep (j, allVertexes[i]->adj.size()) {
            m[allVertexes[i]->adj[j]->id] = true;
        }
    }

    rep (i, allVertexes.size()) {
        if (m.find(allVertexes[i]->id) == m.end()) {
            if (root == -1) {
                root = allVertexes[i]->id;
            } else {
                root = -1;
                break;
            }
        }
    }

    return root;
}

int Graph::countConnectedNodes(vdata root)
{
    map<vdata,bool> visited;
    queue<Vertex*> q;
    Vertex *tmp;
    int count = 0;
    
    tmp = getVertex(root);
    q.push(tmp);
    visited[tmp->id] = true;
    ++count;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        rep (i, tmp->adj.size()) {
            if (visited.find(tmp->adj[i]->id) == visited.end()) {
                visited[tmp->adj[i]->id] = true;
                q.push(tmp->adj[i]);
                count++;
            }
        }
    }

    return count;
}

bool Graph::isTree(int edges_count)
{
    if (allVertexes.size() == 0)
        return true;

    if (edges_count + 1 != allVertexes.size())
        return false;

    vdata root = findRootNode();

    if (root == -1)
        return false;

    return countConnectedNodes(root) == allVertexes.size();
}

int main (void) {
    int a, b, case_number = 0, edges_count = 0;
    Graph *g = new Graph();

    while (cin >> a >> b) {
        if (a == -1 && b == -1)
            break;

        if (a == 0 && b == 0) {
            cout << "Case " << ++case_number << (g->isTree(edges_count) ? " is a tree." : " is not a tree.") << endl;
            delete g;
            g = new Graph();
            edges_count = 0;
        } else {
            edges_count++;
            g->addEdge(a, b, true);
        }
    }

    delete g;

	return 0;
}
