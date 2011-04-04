#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <queue>
using namespace std;

struct Vertex
{
public:
	int id;
	int value;
	Vertex* left;
	Vertex* right;
	Vertex (int id) : id(id) { value = -1; left = right = NULL; }
};

typedef map<int, Vertex*> vmap;
typedef pair<int, Vertex*> vpair;

class BinaryTree
{
public:
	BinaryTree() {}
	~BinaryTree();
	Vertex* addVertex (int v);
	vector<Vertex*> allVertexes;
	void addEdge (int begin, int end, char way);
private:
	Vertex* getVertex (int v);
	vmap vertexMap;
};

BinaryTree::~BinaryTree()
{
	for (int i = 0; i < allVertexes.size(); i++)
		delete allVertexes[i];
}

Vertex* BinaryTree::addVertex (int v) {
	Vertex* newv = new Vertex (v);
	allVertexes.push_back (newv);
	vertexMap.insert (vpair (v, newv));
	return newv;
}

void BinaryTree::addEdge (int begin, int end, char way)
{
	Vertex* v = getVertex (begin);
	Vertex* w = getVertex (end);
	if (way == 'L')
		v->left = w;
	else if (way == 'R')
		v->right = w;
}

Vertex* BinaryTree::getVertex (int v)
{
	vmap::iterator it = vertexMap.find (v);
	
	if (it == vertexMap.end()) {
		return addVertex (v);
	}
	
	return (*it).second;
}

int main (void) {
	string input;
	Vertex* root;
	Vertex* temp;
	int count = 1;
	
	BinaryTree* g = new BinaryTree();
	
	// adding root element
	root = g->addVertex(count++);
	
	bool ok = true;
	while (cin >> input) {
		if (input != "()") {
			if (ok) {
				input = input.substr(1, input.size() - 2);
				size_t found = input.find (",");
				string value = input.substr(0, (int)found);
				string pos = input.substr((int)found+1);
			
				int v = 0;
				reverse (value.begin(), value.end());
				for (int i = 0; i < value.size(); i++)
					v += (value[i] - 48) * pow(10, i);
		
			
				if (pos.size() == 0) {
					if (root->value == -1)
						root->value = v;
					else {
						ok = false;
						continue;
					}
				} else {
					temp = root;
					for (int i = 0; i < pos.size(); i++) {
						if (pos[i] == 'L') {
							if (temp->left == NULL) {
								temp->left = g->addVertex(count);
								temp = temp->left;
								++count;
							} else {
								temp = temp->left;
							}
						} else if (pos[i] == 'R') {
							if (temp->right == NULL) {
								temp->right = g->addVertex(count);
								temp = temp->right;
								++count;
							} else {
								temp = temp->right;
							}
						}
					}
					
					if (temp->value == -1)
						temp->value = v;
					else
						ok = false;
				}
			
				continue;
			}
		} else {
			if (!ok) {
				cout << "not complete" << endl;
			} else {
				for (int i = 0; i < g->allVertexes.size(); i++) {
					if (g->allVertexes[i]->value == -1) {
						ok = false;
						break;
					}
				}
				
				if (!ok) {
					cout << "not complete" << endl;
				} else {
					queue<Vertex*> q;
					q.push(root);
					
					bool first = true;
					
					while (!q.empty()) {
						temp = q.front();
						q.pop();
						
						if (!first) cout << " ";
						else first = false;
						
						cout << temp->value;
						
						if (temp->left != NULL) q.push(temp->left);
						if (temp->right != NULL) q.push(temp->right);
					}
					cout << endl;
				}
			}
			
			ok = true;
			delete g;
			
			g = new BinaryTree();
			count = 1;
			root = g->addVertex(count++);
		}
	}
	
	
	return 0;
}