#include <iostream>
#include <vector>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

vector<int> pset(30000);
vector<int> psize(30000);

void initSet(int n) {
    psize.assign(n, 1);
    rep (i, n) pset[i] = i;
}

int findSet(int v) {
    return (pset[v] == v) ? v : (pset[v] = findSet(pset[v]));
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (psize[a] < psize[b])
            swap(a, b);

        pset[b] = a;
        psize[a] += psize[b];
    }
}

int main(void) {
    int n, m, student, count, other_student;

    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        
        initSet(n);

        while (m--) {
            cin >> count;

            if (count > 0) {
                cin >> student;
                count--;

                while (count--) {
                    cin >> other_student;
                    unionSet(student, other_student);
                }
            }
        }

        cout << psize[findSet(0)] << endl;
    }

    return 0;
}
