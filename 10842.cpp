#include <iostream>
#include <vector>
#include <queue>
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
  int t, n, m, a, b, c;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n >> m;

    priority_queue< pair<int, pair<int,int> > > edgeList;

    while (m--) {
      cin >> a >> b >> c;
      edgeList.push(make_pair(c, make_pair(a, b)));
    }

    int result;
    UnionFindDisjointSets ds(n);

    while (!edgeList.empty()) {
      pair<int, pair<int,int> > front = edgeList.top();
      edgeList.pop();

      if (!ds.isSameSet(front.second.first, front.second.second)) {
        result = front.first;
        ds.unionSet(front.second.first, front.second.second);
      }
    }

    cout << "Case #" << casenum+1 << ": " << result << endl;
  }
  
  return 0;
}
