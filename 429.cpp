#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
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
		Vertex* addVertex (vdata v);
		void addEdge (vdata begin, vdata end, bool directed);
		Vertex* firstVertex();
		int bfs (vdata& b, vdata& e);
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

int Graph::bfs (vdata& b, vdata& e) {
   queue< pair<Vertex*, int> > q;
   Vertex* beginning = getVertex (b);
   pair<Vertex*,int> temp;
   map<string,bool> taken;

   q.push (pair<Vertex*,int>(beginning,0));
   while (!q.empty()) {
      temp = q.front();
      q.pop();

      if (temp.first->id == e) { return temp.second; }

      for (int i = 0; i < temp.first->adj.size(); i++) {
         if (taken[temp.first->adj[i]->id] == false) {
            taken[temp.first->adj[i]->id] = true;
	    q.push (pair<Vertex*, int>(temp.first->adj[i], temp.second + 1));
	 }
      }
   }

   return -1;
}

int main (void) {
   int n, i, j, k;
   string input;
   string beginning, ending;
   vector<string> dic;
   stringstream ss;
   int c = 0;

   Graph* g;

   cin >> n;
   getline(cin,input);
   getline(cin,input);

   while (n--) {
      if (c > 0) cout << endl;
      c++;
      dic.clear();
      g = new Graph();

      while (getline(cin, input)) {
         if (input == "*") break;
         dic.push_back (input);
      }


      for (i = 0; i < dic.size() - 1; i++) {
         for (j = i + 1; j < dic.size(); j++) {
            if (dic[i].size() != dic[j].size()) continue;
            
	    int bad = 0;
	    for (k = 0; k < dic[i].size(); k++) {
               if (dic[i][k] != dic[j][k]) {
                  bad += 1;
		  if (bad > 1) break;
	       }
	    }

	    if (bad < 2) {
               g->addEdge (dic[i], dic[j]);
	    }
	 }
      }


      while (getline(cin, input)) {
         if (input.size() == 0) break;

	 ss << input;

	 ss >> beginning >> ending;


         cout << beginning << " " << ending << " " << g->bfs (beginning, ending) << endl;


	 ss.str(string());
	 ss.clear();
      }

      delete g;
   }
   
   return 0;
}
