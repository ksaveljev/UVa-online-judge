#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

class UnionFindDisjointSets {
  public:
    UnionFindDisjointSets(int size);
    int findSet(int a);
    bool isSameSet(int a, int b);
    void unionSet(int a, int b);
    int numDisjointSets();
    int sizeOfSet(int a);
  private:
    int size;
    vector<int> pset;
    vector<int> set_size;
};

UnionFindDisjointSets::UnionFindDisjointSets(int size) {
  this->size = size;

  set_size.assign(size, 1);
  pset.assign(size, 0);

  for (int i = 0; i < size; i++)
    pset[i] = i;
}

int UnionFindDisjointSets::findSet(int a) {
  return pset[a] == a ? a : (pset[a] = findSet(pset[a]));
}

bool UnionFindDisjointSets::isSameSet(int a, int b) {
  return findSet(a) == findSet(b);
}

void UnionFindDisjointSets::unionSet(int a, int b) {
  if (isSameSet(a, b)) return;

  size--;
  set_size[findSet(b)] += set_size[findSet(a)];
  pset[findSet(a)] = findSet(b);
}

int UnionFindDisjointSets::numDisjointSets() {
  return size;
}

int UnionFindDisjointSets::sizeOfSet(int a) {
  return set_size[findSet(a)];
}

int main(void)
{
  int s, c, cost;
  string input, a, b;

  while (cin >> s >> c) {
    if (!s && !c) {
      break;
    }

    map<string,int> m;
    int counter = 0;
    priority_queue< pair<int, pair<int,int> > > edgeList;

    for (int i = 0; i < s; i++) {
      cin >> input;
      m[input] = counter++;
    }

    for (int i = 0; i < c; i++) {
      cin >> a >> b >> cost;
      edgeList.push(make_pair(-cost, make_pair(m[a],m[b])));
    }

    cin >> a;

    int mst_cost = 0;
    UnionFindDisjointSets ds(s);

    while (!edgeList.empty()) {
      pair<int, pair<int,int> > front = edgeList.top();
      edgeList.pop();

      if (!ds.isSameSet(front.second.first, front.second.second)) {
        mst_cost += (-front.first);
        ds.unionSet(front.second.first, front.second.second);
      }
    }

    if (ds.sizeOfSet(0) != s) {
      cout << "Impossible" << endl;
    } else {
      cout << mst_cost << endl;
    }
  }
  
  return 0;
}
