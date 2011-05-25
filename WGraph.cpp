#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef int vdata;

struct Vertex {
  vdata id;
  vector< pair<Vertex*, int> > adj;
  Vertex (vdata id) : id(id) {}
};

typedef map<vdata, Vertex*> vmap;
typedef pair<vdata, Vertex*> vpair;


class WGraph {
  public:
    WGraph() {}
    ~WGraph();
    Vertex* addVertex (vdata v);
    void addEdge (vdata begin, vdata end, int weight, bool directed);
    Vertex* getVertex (vdata v);
  private:
    vmap vertexMap;
    vmap::iterator it;
    vector<Vertex*> allVertexes;
};

WGraph::~WGraph() {
  for (int i = 0, sz = allVertexes.size(); i < sz; i++)
    delete allVertexes[i];
}

Vertex* WGraph::addVertex (vdata v) {
  Vertex* newv = new Vertex (v);
  allVertexes.push_back (newv);
  vertexMap.insert (vpair (v, newv));
  return newv;
}

Vertex* WGraph::getVertex (vdata v) {
  it = vertexMap.find (v);

  if (it == vertexMap.end())
    return addVertex (v);

  return it->second;
}

void WGraph::addEdge (vdata begin, vdata end, int weight, bool directed = false) {
  Vertex* a = getVertex (begin);
  Vertex* b = getVertex (end);
  a->adj.push_back (make_pair (b, weight));
  if (!directed)
    b->adj.push_back (make_pair (a, weight));
}

int main(void) {
  return 0;
}
