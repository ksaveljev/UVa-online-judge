#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool visited[15];
vector< pair<int,int> > pieces;

bool solution_exists(int start, int end, int n) {
    if (n == 0) {
        if (start == end) return true;
        else return false;
    }

    for (int i = 0, sz = pieces.size(); i < sz; i++) {
        if (!visited[i]) {
            if (pieces[i].first == start) {
                visited[i] = true;
                bool result = solution_exists(pieces[i].second, end, n - 1);
                visited[i] = false;
                if (result) return true;
            } else if (pieces[i].second == start) {
                visited[i] = true;
                bool result = solution_exists(pieces[i].first, end, n - 1);
                visited[i] = false;
                if (result) return true;
            }
        }
    }
    return false;
}

int main(void) {
    int n, m;
    pair<int,int> start, end, tmp;
    
    while (cin >> n) {
        if (n == 0) break;
        cin >> m;

        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        for (int i = 0; i < 15; i++)
            visited[i] = false;

        pieces.clear();

        for (int i = 0; i < m; i++) {
            cin >> tmp.first >> tmp.second;
            pieces.push_back(tmp);
        }

        if (solution_exists(start.second, end.first, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
