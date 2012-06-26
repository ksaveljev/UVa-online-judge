#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int field[4][4];
bool solution_found;
vector<char> steps;
vector<char> solution_steps;

pair<int,int> find_pos(int field[4][4], int c) {
    rep (i, 4)
        rep (j, 4)
            if (field[i][j] == c)
                return make_pair(i,j);
}

int nr_of_inversions(int f[16]) {
    int result = 0;

    rep (i, 16) {
        REP (j, i+1, 16) {
            if (f[i] == 0 || f[j] == 0)
                continue;

            if (f[i] > f[j])
                result++;
        }
    }

    return result;
}

bool is_solvable() {
    int f[16];

    rep (i, 4)
        rep (j, 4)
            f[i*4+j] = field[i][j];

    pair<int,int> blank = find_pos(field, 0);
    int count = nr_of_inversions(f);

    if ((4 - blank.first) % 2 == 0) {
        return count % 2 == 1;
    } else {
        return count % 2 == 0;
    }
}

int heuristic(int field[4][4]) {
    static int f[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
    int result = 0;

    REP (i, 1, 16) {
        pair<int,int> pos1 = find_pos(field, i);
        pair<int,int> pos2 = find_pos(f, i);

        result += abs(pos1.first - pos2.first);
        result += abs(pos1.second - pos2.second);
    }

    return result;
}

bool is_goal_reached() {
    static int f[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};

    rep (i, 4)
        rep (j, 4)
            if (field[i][j] != f[i][j])
                return false;

    return true;
}

void find_solution(int limit, char prev_move) {
    if (solution_found || is_goal_reached()) {
        solution_found = true;
        solution_steps = steps;
        return;
    }

    pair<int,int> blank = find_pos(field, 0);

    /*
    cout << "Current field:" << endl;
    rep (i, 4) {
        rep (j, 4) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Steps taken to reach this field: ";
    rep (i, steps.size())
        cout << steps[i];
    cout << endl;
    cout << "f(s) = h(s) + g(s) = " << heuristic(field) + steps.size() << endl;
    cout << "current limit = " << limit << endl;
    */

    // up
    if (blank.first > 0 && prev_move != 'D') {
        swap(field[blank.first][blank.second], field[blank.first-1][blank.second]);

        int h = heuristic(field);

        if (h + steps.size() + 1 <= limit && !solution_found) {
            steps.push_back('U');
            find_solution(limit, 'U');
            steps.pop_back();
        }

        swap(field[blank.first][blank.second], field[blank.first-1][blank.second]);
    }

    // down
    if (blank.first < 3 && prev_move != 'U') {
        swap(field[blank.first][blank.second], field[blank.first+1][blank.second]);

        int h = heuristic(field);

        if (h + steps.size() + 1 <= limit && !solution_found) {
            steps.push_back('D');
            find_solution(limit, 'D');
            steps.pop_back();
        }

        swap(field[blank.first][blank.second], field[blank.first+1][blank.second]);
    }

    // left
    if (blank.second > 0 && prev_move != 'R') {
        swap(field[blank.first][blank.second], field[blank.first][blank.second-1]);

        int h = heuristic(field);

        if (h + steps.size() + 1 <= limit && !solution_found) {
            steps.push_back('L');
            find_solution(limit, 'L');
            steps.pop_back();
        }

        swap(field[blank.first][blank.second], field[blank.first][blank.second-1]);
    }
    
    // right
    if (blank.second < 3 && prev_move != 'L') {
        swap(field[blank.first][blank.second], field[blank.first][blank.second+1]);

        int h = heuristic(field);

        if (h + steps.size() + 1 <= limit && !solution_found) {
            steps.push_back('R');
            find_solution(limit, 'R');
            steps.pop_back();
        }

        swap(field[blank.first][blank.second], field[blank.first][blank.second+1]);
    }
}

int main(void) {
    int n;

    cin >> n;

    while (n--) {
        rep (i, 4)
            rep (j, 4)
                cin >> field[i][j];

        if (!is_solvable()) {
            cout << "This puzzle is not solvable." << endl;
            continue;
        }

        int h = heuristic(field);
        solution_found = false;
        steps.clear();

        while (true) {
            find_solution(h, ' ');

            if (solution_found) {
                rep (i, solution_steps.size())
                    cout << solution_steps[i];
                cout << endl;
                break;
            } else {
                h += 5;
            }
        }
    }

    return 0;
}
