#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    string input;

    cin >> n;
    getline(cin, input); // read \n after n

    for (int casenum = 1; casenum <= n; casenum++) {
        getline(cin, input);

        int max = 0, min = 0, cur = 0;
        
        for (int i = 0, sz = input.size(); i < sz; i++) {
            switch (input[i]) {
                case 'R':
                    cur++;
                    if (cur > max)
                        max = cur;
                    break;
                case 'F':
                    cur--;
                    if (cur < min)
                        min = cur;
                    break;
                case 'C':
                    break;
            }
        }

        int height = max - min + 1;
        char graph[height][input.size()];

        for (int i = 0; i < height; i++)
            for (int j = 0, sz = input.size(); j < sz; j++)
                graph[i][j] = ' ';

        cur = -min;
        for (int i = 0, sz = input.size(); i < sz; i++) {
            switch (input[i]) {
                case 'R':
                    graph[cur][i] = '/';
                    cur++;
                    break;
                case 'F':
                    cur--;
                    graph[cur][i] = '\\';
                    break;
                case 'C':
                    graph[cur][i] = '_';
                    break;
            }
        }

        cout << "Case #" << casenum << ":" << endl;

        for (int i = height - 1; i >= 0; i--) {
            int last_pos = -1;
            for (int j = 0, sz = input.size(); j < sz; j++) {
                if (graph[i][j] != ' ')
                    last_pos = j;
            }

            if (last_pos > -1) {
                cout << "| ";

                for (int j = 0; j <= last_pos; j++) {
                    cout << graph[i][j];
                }

                cout << endl;
            }
        }

        cout << "+-";
        for (int i = 0, sz = input.size(); i <= sz; i++)
            cout << "-";
        cout << endl;

        cout << endl;
    }

    return 0;
}
