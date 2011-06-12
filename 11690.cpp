#include <iostream>
#include <vector>
#include <map>
using namespace std;

class UnionFindDisjointSets {
  public:
    UnionFindDisjointSets(int size, int *pay);
    int findSet(int a);
    bool isSameSet(int a, int b);
    void unionSet(int a, int b);
    int numDisjointSets();
    int sizeOfSet(int a);
    int getMoney(int a);
  private:
    int size;
    vector<int> pset;
    vector<int> set_size;
    vector<int> money;
};

UnionFindDisjointSets::UnionFindDisjointSets(int size, int *pay) {
  this->size = size;

  set_size.assign(size, 1);
  pset.assign(size, 0);
  money.assign(size, 0);

  for (int i = 0; i < size; i++) {
    pset[i] = i;
    money[i] = pay[i];
  }
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
  money[findSet(b)] += money[findSet(a)];
  pset[findSet(a)] = findSet(b);
}

int UnionFindDisjointSets::numDisjointSets() {
  return size;
}

int UnionFindDisjointSets::sizeOfSet(int a) {
  return set_size[findSet(a)];
}

int UnionFindDisjointSets::getMoney(int a) {
  return money[findSet(a)];
}

int main(void) {
  int t;
  int n, m;
  int a, b;
  int pay[10001];

  cin >> t;

  while (t--) {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
      cin >> pay[i];

    UnionFindDisjointSets ds(n, pay);

    while (m--) {
      cin >> a >> b;
      ds.unionSet(a, b);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (ds.getMoney(i) != 0) {
        ok = false;
        break;
      }
    }

    if (ok)
      cout << "POSSIBLE" << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
