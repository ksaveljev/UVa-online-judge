#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

class UnionFindDisjointSets {
    public:
        UnionFindDisjointSets(int size);
        int findSet(int a);
        bool isSameSet(int a, int b);
        void unionSet(int a, int b);
        int numDisjointSets();
        int sizeOfSet(int a);
        int numFaces();
    private:
        int faces;
        int size;
        vector<int> pset;
        vector<int> set_size;
};

UnionFindDisjointSets::UnionFindDisjointSets(int size) {
    this->faces = 1;
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
    if (isSameSet(a, b)) {
        faces++;
        return;
    }

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

int UnionFindDisjointSets::numFaces() {
    return faces;
}

int main(void) {
    int N, E;
    char a, b;

    while (cin >> N >> E) {
        UnionFindDisjointSets ds(10*N);

        while (E--) {
            cin >> a >> b;
            ds.unionSet(int(a - 'A'), int(b - 'A'));
        }

        cout << ds.numFaces() << endl;
    }

    return 0;
}
