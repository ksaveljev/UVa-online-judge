#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
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

int distance(int start, int end, int n, const vector< pair<int, pair<int,int> > > &mst)
{
  if (start == end) {
    return 0;
  }

  bool visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }

  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = start;
  tmp.second = 1000000000;
  q.push(tmp);

  visited[start] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first == end) {
      return tmp.second;
    }

    for (int i = 0, sz = mst.size(); i < sz; i++) {
      if (mst[i].second.first == tmp.first) {
        if (!visited[mst[i].second.second]) {
          visited[mst[i].second.second] = true;
          q.push(make_pair(mst[i].second.second, min(tmp.second, mst[i].first)));
        }
      } else if (mst[i].second.second == tmp.first) {
        if (!visited[mst[i].second.first]) {
          visited[mst[i].second.first] = true;
          q.push(make_pair(mst[i].second.first, min(tmp.second, mst[i].first)));
        }
      }
    }
  }

  return -1;
}

int main(void)
{
  int n, r, c;
  string a, b;
  int casenum = 0;

  while (cin >> n >> r) {
    if (!n && !r) {
      break;
    }

    casenum++;

    int counter = 0;
    map<string,int> m;
    priority_queue< pair<int, pair<int,int> > > edgeList;

    while (r--) {
      cin >> a >> b >> c;

      if (m.find(a) == m.end()) {
        m[a] = counter++;
      }

      if (m.find(b) == m.end()) {
        m[b] = counter++;
      }

      edgeList.push(make_pair(c, make_pair(m[a], m[b])));
    }

    cin >> a >> b;

    UnionFindDisjointSets ds(n);
    vector< pair<int, pair<int,int> > > mst;

    while (!edgeList.empty()) {
      pair<int, pair<int,int> > front = edgeList.top();
      edgeList.pop();

      if (!ds.isSameSet(front.second.first, front.second.second)) {
        ds.unionSet(front.second.first, front.second.second);
        mst.push_back(front);
      }
    }

    cout << "Scenario #" << casenum << endl;
    cout << distance(m[a], m[b], n, mst) << " tons" << endl;
    cout << endl;
  }
  
  return 0;
}
