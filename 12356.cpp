#include <iostream>
#include <cstdio>
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

int main(void) {
    int S, B, L, R;
    int *left = new int[100005];
    int *right = new int[100005];

    while (cin >> S >> B) {
        if (S == 0 && B == 0) break;

        repi (i, S) {
            left[i] = i - 1;
            right[i] = i + 1;
        }

        while (B--) {
            scanf("%d %d", &L, &R);

            if (left[L] < 1) printf("* ");
            else printf("%d ", left[L]);

            if (right[R] > S) printf("*\n");
            else printf("%d\n", right[R]);

            left[right[R]] = left[L];
            right[left[L]] = right[R];
        }
        cout << "-" << endl;
    }

    delete left;
    delete right;

    return 0;
}
