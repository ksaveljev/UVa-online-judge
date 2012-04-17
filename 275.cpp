#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;

        int length;
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
                break;
            } else if (a < b) {
                v.push_back(0);
                a *= 10;
                continue;
            }

            v.push_back(a / b);
            a = (a % b) * 10;
        }

        cout << ".";

        int counter = 1;

        rep (i, v.size()) {
            if (counter == 50) {
                counter = 0;
                cout << endl;
            }

            counter++;
            cout << v[i];
        }

        cout << endl;

        if (a == 0) {
            cout << "This expansion terminates." << endl;
        } else {
            cout << "The last " << length << " digits repeat forever." << endl;
        }

        cout << endl;
    }

    return 0;
}
