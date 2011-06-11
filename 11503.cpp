#include <iostream>
#include <vector>
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

int main(void) {
  int t;
  int n;
  string a, b;

  cin >> t;

  while (t--) {
    int counter = 0;
    map<string,int> m;
    UnionFindDisjointSets ds(200000);

    cin >> n;

    while (n--) {
      cin >> a >> b;

      if (m.find(a) == m.end()) {
        m[a] = counter;
        counter++;
      }

      if (m.find(b) == m.end()) {
        m[b] = counter;
        counter++;
      }

      ds.unionSet(m[a], m[b]);
      cout << ds.sizeOfSet(m[a]) << endl;
    }
  }

  return 0;
}
