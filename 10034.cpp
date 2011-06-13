#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
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

int main(void) {
  int t, n;
  double x, y;

  cin >> t;

  while (t--) {
    cin >> n;

    vector< pair<double,double> > dots;
    priority_queue< pair<double, pair<int,int> > > edgeList;

    while (n--) {
      cin >> x >> y;

      for (int i = 0, sz = dots.size(); i < sz; i++) {
        double dist = sqrt((x-dots[i].first)*(x-dots[i].first) + (y-dots[i].second)*(y-dots[i].second));
        edgeList.push(make_pair(-dist, make_pair(i, sz)));
      }

      dots.push_back(make_pair(x, y));
    }

    double mst_cost = 0;
    UnionFindDisjointSets ds(dots.size());

    while (!edgeList.empty()) {
      pair< double, pair<int,int> > front = edgeList.top();
      edgeList.pop();

      if (!ds.isSameSet(front.second.first, front.second.second)) {
        mst_cost += (-front.first);
        ds.unionSet(front.second.first, front.second.second);
      }
    }

    cout << setprecision(2) << fixed << showpoint << mst_cost << endl;

    if (t)
      cout << endl;
  }

  return 0;
}
