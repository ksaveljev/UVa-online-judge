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
  int t, s, p;
  double x, y;
  int limit;

  cin >> t;

  while (t--) {
    cin >> s >> p;

    limit = p - s;

    vector< pair<double,double> > outposts;
    priority_queue< pair<double, pair<int,int> > > edgeList;

    while (p--) {
      cin >> x >> y;

      for (int i = 0, sz = outposts.size(); i < sz; i++) {
        double dist = sqrt((x-outposts[i].first)*(x-outposts[i].first) + (y-outposts[i].second)*(y-outposts[i].second));
        edgeList.push(make_pair(-dist, make_pair(i, sz)));
      }

      outposts.push_back(make_pair(x, y));
    }

    double result = 0;
    int counter = 0;
    UnionFindDisjointSets ds(outposts.size());

    while (counter < limit) {
      pair< double, pair<int,int> > front = edgeList.top();
      edgeList.pop();

      if (!ds.isSameSet(front.second.first, front.second.second)) {
        counter++;
        if (-front.first > result) {
          result = -front.first;
        }
        ds.unionSet(front.second.first, front.second.second);
      }
    }

    cout << setprecision(2) << fixed << showpoint << result << endl;
  }

  return 0;
}
