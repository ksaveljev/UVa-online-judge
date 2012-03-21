#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int binary_search(int *chimps, int n, int h) {
    int start = 0, end = n - 1, mid;

    while (end > start) {
        mid = (start + end) / 2;

        if (chimps[mid] < h) {
            start = mid + 1;
        } else if (chimps[mid] > h) {
            end = mid - 1;
        } else
            return mid;
    }

    return start;
}

int main(void) {
    int n, q, h;
    int counter = 0;
    int *chimps = new int[50000];

    cin >> n;

    rep(i, n) {
        scanf("%d", &chimps[counter]);
        if (counter == 0 || chimps[counter] > chimps[counter-1])
            counter++;
    }

    n = counter;

    cin >> q;

    while (q--) {
        scanf("%d", &h);

        int index = binary_search(chimps, n, h);
        
        if (chimps[index] == h) {
            if (index - 1 >= 0)
                cout << chimps[index-1];
            else
                cout << "X";

            cout << " ";

            if (index + 1 < n)
                cout << chimps[index+1];
            else
                cout << "X";

            cout << endl;
        } else if (chimps[index] > h) {
            if (index - 1 >= 0)
                cout << chimps[index-1];
            else
                cout << "X";
            
            cout << " " << chimps[index] << endl;
        } else if (chimps[index] < h) {
            cout << chimps[index] << " ";

            if (index + 1 < n)
                cout << chimps[index+1];
            else
                cout << "X";

            cout << endl;
        }
    }

    delete [] chimps;

    return 0;
}
