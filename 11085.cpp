#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int N = 8;

int distanceToSolution(vector<int> &permutation, vector<int> &solution) {
    int distance = 0;

    rep (i, N) {
        if (permutation[i] != solution[i])
            distance++;
    }

    return distance;
}

int main(void) {
    int pos, caseNumber = 0;
    vector<int> permutation;
    vector< vector<int> > solutions;

    rep (i, N) {
        permutation.push_back(i);
    }

    do {
        set<int> diag1, diag2;

        rep (i, N) {
            diag1.insert(permutation[i] + i);
            diag2.insert(permutation[i] - i);
        }

        if (N == diag1.size() && N == diag2.size()) {
            solutions.push_back(permutation);
        }
    } while (next_permutation(permutation.begin(), permutation.end()));


    while (cin >> pos) {
        caseNumber++;
        permutation.clear();
        permutation.push_back(pos-1);

        rep (i, N-1) {
            cin >> pos;
            permutation.push_back(pos-1);
        }

        int result = 999999999;

        rep (i, solutions.size())
            result = min(result, distanceToSolution(permutation, solutions[i]));

        cout << "Case " << caseNumber << ": " << result << endl;
    }

    return 0;
}
