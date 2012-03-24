#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

string moves[] = { "+y", "-y", "+z", "-z", "+x", "-x" };

// there are 6 directions the wire can be pointing at:
// +x -x +y -y +z -z
// there are 4 different directions of the bend
// +y -y +z -z
//
// we keep a precalculated table to instantly get the
// result of where the wire is pointing after the bend
int precalc[6][4] = {
    { 5, 4, 0, 0 },
    { 4, 5, 1, 1 },
    { 2, 2, 5, 4 },
    { 3, 3, 4, 5 },
    { 0, 1, 2, 3 },
    { 1, 0, 3, 2 }
};

int move_to_int(string &move) {
    int result;

    rep (i, 6) {
        if (moves[i] == move) {
            result = i;
            break;
        }
    }

    return result;
}

string int_to_move(int move) {
    return moves[move];
}

int main(void) {
    int L, direction;
    string move;

    while (cin >> L) {
        if (L == 0)
            break;

        // 4 stands for +x from the moves[]
        direction = 4;

        rep (i, L-1) {
            cin >> move;

            if (move == "No")
                continue;

            direction = precalc[direction][move_to_int(move)];
        }

        cout << int_to_move(direction) << endl;
    }

    return 0;
}
