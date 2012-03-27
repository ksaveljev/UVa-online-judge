#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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
        set<int> fallen_trees[100];
        void combine(int P);
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

void UnionFindDisjointSets::combine(int P) {
    rep (i, P) {
        REP (j, i+1, P) {
            if (!isSameSet(i, j)) {
                vector<int> diff;
                set_symmetric_difference(fallen_trees[i].begin(), fallen_trees[i].end(), fallen_trees[j].begin(), fallen_trees[j].end(), back_inserter(diff));

                if (diff.empty()) {
                    unionSet(i, j);
                }
            }
        }
    }
}

int main(void) {
    int t, person, tree, highest_person_number, P, T;

    cin >> t;

    while (t--) {

        cin >> P >> T;
        cin.ignore(100, '\n');

        UnionFindDisjointSets ds(P);

        while (cin.peek() != '\n' && cin.peek() != -1) {
            cin >> person >> tree;
            cin.ignore(100, '\n');

            ds.fallen_trees[person-1].insert(tree);
        }

        ds.combine(P);

        cout << ds.numDisjointSets() << endl;

        if (t)
            cout << endl;
    }

    return 0;
}
