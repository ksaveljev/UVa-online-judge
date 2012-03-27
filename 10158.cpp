#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define E(c) ((c % 2) ? (c + 1) : (c - 1))

class UnionFindDisjointSets {
    public:
        UnionFindDisjointSets(int size);
        int findSet(int a);
        bool isSameSet(int a, int b);
        void unionSet(int a, int b);
        int numDisjointSets();
        int sizeOfSet(int a);
        bool areEnemies(int a, int b);
        bool areFriends(int a, int b);
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

bool UnionFindDisjointSets::areEnemies(int a, int b) {
    return findSet(a) == findSet(E(b)) || findSet(b) == findSet(E(a));
}

bool UnionFindDisjointSets::areFriends(int a, int b) {
    return findSet(a) == findSet(b) || findSet(E(a)) == findSet(E(b));
}

int main(void) {
    int n, c, a, b;

    cin >> n;

    UnionFindDisjointSets ds(2 * n);

    while (cin >> c >> a >> b) {
        if (c == 0 && a == 0 && b == 0)
            break;

        a = a * 2 + 1;
        b = b * 2 + 1;

        switch (c) {
            case 1:
                // setFriends
                if (ds.areEnemies(a, b))
                    cout << "-1" << endl;
                else
                    ds.unionSet(a, b), ds.unionSet(E(a), E(b));
                break;
            case 2:
                // setEnemies
                if (ds.areFriends(a, b))
                    cout << "-1" << endl;
                else
                    ds.unionSet(a, E(b)), ds.unionSet(b, E(a));
                break;
            case 3:
                // areFriends
                cout << (ds.areFriends(a, b) ? "1" : "0") << endl;
                break;
            case 4:
                // areEnemies
                cout << (ds.areEnemies(a, b) ? "1" : "0") << endl;
                break;
        }
    }

    return 0;
}
