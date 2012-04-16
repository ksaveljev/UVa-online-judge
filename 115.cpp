#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef string vdata;

struct Vertex 
{
	public:
		vdata id;
		vector<Vertex*> children;
        vector<Vertex*> parents;
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
        void addChild (vdata parent, vdata child);
        void addParent (vdata child, vdata parent);
		Vertex* firstVertex();
        bool areSiblings(vdata a, vdata b);
        int findChild(vdata parent, vdata child);
        int findParent(vdata child, vdata parent);
        pair<int,int> findRelation(vdata a, vdata b);
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

void Graph::addChild (vdata parent, vdata child) {
    Vertex* v = getVertex(parent);
    Vertex* w = getVertex(child);

    v->children.push_back(w);
}

void Graph::addParent (vdata child, vdata parent) {
    Vertex* v = getVertex(child);
    Vertex* w = getVertex(parent);

    v->parents.push_back(w);
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

bool Graph::areSiblings(vdata a, vdata b) {
    Vertex* v = getVertex(a);
    Vertex* w = getVertex(b);

    for (int i = 0, sz = v->parents.size(); i < sz; i++) {
        for (int j = 0, sz2 = w->parents.size(); j < sz2; j++) {
            if (v->parents[i]->id == w->parents[j]->id)
                return true;
        }
    }

    return false;
}

int Graph::findChild(vdata parent, vdata child) {
    queue< pair<Vertex*, int> > q;
    pair<Vertex*, int> tmp;

    Vertex* v = getVertex(parent);

    for (int i = 0, sz = v->children.size(); i < sz; i++) {
        q.push(make_pair(v->children[i], 1));
    }
    
    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.first->id == child) {
            return tmp.second;
        }

        for (int i = 0, sz = tmp.first->children.size(); i < sz; i++) {
            q.push(make_pair(tmp.first->children[i], tmp.second + 1));
        }
    }

    return -1;
}

int Graph::findParent(vdata child, vdata parent) {
    queue< pair<Vertex*, int> > q;
    pair<Vertex*, int> tmp;

    Vertex* v = getVertex(child);

    for (int i = 0, sz = v->parents.size(); i < sz; i++) {
        q.push(make_pair(v->parents[i], 1));
    }

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.first->id == parent) {
            return tmp.second;
        }

        for (int i = 0, sz = tmp.first->parents.size(); i < sz; i++) {
            q.push(make_pair(tmp.first->parents[i], tmp.second + 1));
        }
    }

    return -1;
}

pair<int,int> Graph::findRelation(vdata a, vdata b) {
    int n;
    queue< pair<Vertex*, int> > q;
    pair<Vertex*, int> tmp;

    Vertex* v = getVertex(a);

    for (int i = 0, sz = v->parents.size(); i < sz; i++) {
        q.push(make_pair(v->parents[i], 1));
    }

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        n = findChild(tmp.first->id, b);

        if (n != -1) {
            return make_pair(tmp.second, n);
        }

        for (int i = 0, sz = tmp.first->parents.size(); i < sz; i++) {
            q.push(make_pair(tmp.first->parents[i], tmp.second + 1));
        }
    }

    return make_pair(-1, -1);
}

int main(void) {
    Graph g;
    string a, b;
    int n;

    while (cin >> a) {
        if (a == "no.child") {
            getline(cin, a);
            break;
        }

        cin >> b;

        g.addChild(b, a);
        g.addParent(a, b);
    }

    while (cin >> a >> b) {
        if (g.areSiblings(a, b)) {
            cout << "sibling" << endl;
            continue;
        }

        n = g.findParent(b, a);

        if (n != -1) {
            if (n > 1) {
                if (n > 2) {
                    for (int i = 0; i < n - 2; i++) {
                        cout << "great ";
                    }
                }
                cout << "grand ";
            }

            cout << "parent" << endl;
            continue;
        }

        n = g.findChild(b, a);

        if (n != -1) {
            if (n > 1) {
                if (n > 2) {
                    for (int i = 0; i < n - 2; i++) {
                        cout << "great ";
                    }
                }
                cout << "grand ";
            }

            cout << "child" << endl;
            continue;
        }

        pair<int,int> r = g.findRelation(a, b);

        if (r.first != -1) {
            cout << min(r.first - 1, r.second - 1) << " cousin";

            if (r.first - r.second != 0) {
                if (r.first < r.second)
                    swap(r.first, r.second);

                cout << " removed " << r.first - r.second;
            }

            cout << endl;

            continue;
        }

        cout << "no relation" << endl;
    }

    return 0;
}
