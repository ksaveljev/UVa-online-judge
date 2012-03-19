#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int p, r;
    int case_num = 0;
    string a, b;
    int connections[51][51];
    int DISCONNECTED = 999999999;

    while (cin >> p >> r) {
        if (p == 0 && r == 0)
            break;

        case_num++;

        map<string,int> people;
        int counter = 0;

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (i == j) {
                    connections[i][j] = 0;
                    continue;
                }

                connections[i][j] = DISCONNECTED;
            }
        }

        while (r--) {
            cin >> a >> b;

            if (people.find(a) == people.end()) {
                people[a] = counter;
                counter++;
            }

            if (people.find(b) == people.end()) {
                people[b] = counter;
                counter++;
            }

            connections[people[a]][people[b]] = 1;
            connections[people[b]][people[a]] = 1;
        }

        for (int k = 0; k < p; k++) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    connections[i][j] = min(connections[i][j], connections[i][k] + connections[k][j]);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (connections[i][j] == DISCONNECTED) {
                    result = -1;
                    i = p;
                    break;
                }

                result = max(result, connections[i][j]);
            }
        }

        cout << "Network " << case_num << ": ";

        if (result == -1) {
            cout << "DISCONNECTED" << endl;
        } else {
            cout << result << endl;
        }

        cout << endl;
    }

    return 0;
}
