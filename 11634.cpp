#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int num_size(int n) {
    return log10(n) + 1;
}

int main(void) {
    int a;
    int N = 4;

    while (cin >> a) {
        if (a == 0)
            break;

        int counter = 0;
        map<int, bool> visited;

        visited[a] = true;
        counter++;

        while (true) {
            a = a * a;

            a /= 100;
            a %= 10000;

            if (visited.find(a) == visited.end()) {
                counter++;
                visited[a] = true;
            } else
                break;
        }

        cout << counter << endl;
    }

    return 0;
}
