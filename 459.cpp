#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef char vdata;

struct Vertex 
{
	public:
		vdata id;
		bool counted;
		vector<Vertex*> adj;
		Vertex (vdata id) : id(id) { counted = false; }
};

typedef map<vdata, Vertex*> vmap;
typedef pair<vdata, Vertex*> vpair;

queue<Vertex*> q;

class Graph 
{
	public:
		Graph() {}
		~Graph();
		Vertex* addVertex (vdata v);
		void addEdge (vdata begin, vdata end, bool directed);
		Vertex* firstVertex();
		int countSubGraphs();
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

int Graph::countSubGraphs()
{
	int sum = 0;
	Vertex* temp;
	
	for (int i = 0; i< allVertexes.size(); i++) {
		if (allVertexes[i]->counted == false) {
			++sum;
			q.push(allVertexes[i]);
			
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				
				temp->counted = true;
				
				for (int j = 0; j < temp->adj.size(); j++) {
					if (temp->adj[j]->counted == false) {
						temp->adj[j]->counted = true;
						q.push(temp->adj[j]);
					}
				}
			}
		}
	}
	
	return sum;
}

void TrimSpaces( string& str)
{
    size_t startpos = str.find_first_not_of(" \t");
    size_t endpos = str.find_last_not_of(" \t");
 
    if(( string::npos == startpos ) || ( string::npos == endpos))
    {
        str = "";
    }
    else
        str = str.substr( startpos, endpos-startpos+1 );
}

int main (void) {
	int n;
	char c, d;
	char prev = 'a';
	int counter = 0;
	string input;
	
	cin >> n;
	getline(cin,input);
	getline(cin,input);
	
	while (n--) {
		counter++;
		Graph* g = new Graph();
		
		getline(cin,input);
		TrimSpaces(input);
		
		for (char i = 'A'; i <= input[0]; i++)
			g->addVertex(i);
		
		while (getline(cin,input)) {
			TrimSpaces(input);
			
			if (input.size() == 0) break;
			
			g->addEdge (input[0],input[1]);
		}
		
		if (counter > 1) cout << endl;
		cout << g->countSubGraphs() << endl;
		
		
		delete g;
	}	
	
	return 0;
}