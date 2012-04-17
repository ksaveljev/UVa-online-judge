#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int a, b;

    while (cin >> a >> b) {
        int initial_a, initial_b;

        initial_a = a;
        initial_b = b;

        int length;
        int n = a / b;
        vector<int> v;
        map<int,int> visited;

        a = (a % b) * 10;

        while (true) {
            if (visited.find(a) != visited.end()) {
                length = v.size() - visited[a];
                break;
            }

            visited[a] = v.size();

            if (a == 0) {
                length = 1;
                v.push_back(0);
                break;
            } else if (a < b) {
                v.push_back(0);
                a *= 10;
                continue;
            }

            v.push_back(a / b);
            a = (a % b) * 10;
        }

        cout << initial_a << "/" << initial_b << " = " << n << ".";

        rep (i, v.size()) {
            if (i == 50) {
                cout << "...";
                break;
            }
            if (i == visited[a]) {
                cout << "(";
            }
            cout << v[i];
        }
        cout << ")" << endl;

        cout << "   " << length << " = number of digits in repeating cycle" << endl;

        cout << endl;
    }

    return 0;
}
