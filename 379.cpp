#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef struct _move {
    pair<int,int> from;
    pair<int,int> to;
    pair<int,int> remove;
    bool found;
} move;

int field[9][9] = {
    {0,  0,  0,  0,  0,  0,  0,  0,  0},
    {0,  0,  0,  1,  2,  3,  0,  0,  0},
    {0,  0,  0,  4,  5,  6,  0,  0,  0},
    {0,  7,  8,  9, 10, 11, 12, 13,  0},
    {0, 14, 15, 16, 17, 18, 19, 20,  0},
    {0, 21, 22, 23, 24, 25, 26, 27,  0},
    {0,  0,  0, 28, 29, 30,  0,  0,  0},
    {0,  0,  0, 31, 32, 33,  0,  0,  0},
    {0,  0,  0,  0,  0,  0,  0,  0,  0}
};
bool pegs[9][9];

void clear_pegs() {
    rep(i, 9)
        rep(j, 9)
            pegs[i][j] = false;
}

void set_peg(int peg) {
    rep(i, 9) {
        rep(j, 9) {
            if (field[i][j] == peg)
                pegs[i][j] = true;
        }
    }
}

move find_next_move() {
    move result;
    result.found = false;
    pair<int,int> to_field, from_field, remove_field;
    int from = 0, to = 0;

    rep(i, 9) {
        rep(j, 9) {
            if (pegs[i][j]) {
                // left
                if (pegs[i][j-1] && !pegs[i][j+1]) {
                    if (field[i][j+1] > to || field[i][j+1] == to && to > 0 && field[i][j-1] > from) {
                        to = field[i][j+1];
                        to_field = make_pair(i, j+1);
                        from = field[i][j-1];
                        from_field = make_pair(i, j-1);
                        result.found = true;

                        remove_field = make_pair(i, j);
                    }
                }

                // top
                if (pegs[i-1][j] && !pegs[i+1][j]) {
                    if (field[i+1][j] > to || field[i+1][j] == to && to > 0 && field[i-1][j] > from) {
                        to = field[i+1][j];
                        to_field = make_pair(i+1, j);
                        from = field[i-1][j];
                        from_field = make_pair(i-1, j);
                        result.found = true;

                        remove_field = make_pair(i, j);
                    }
                }

                // right
                if (pegs[i][j+1] && !pegs[i][j-1]) {
                    if (field[i][j-1] > to || field[i][j-1] == to && to > 0 && field[i][j+1] > from) {
                        to = field[i][j-1];
                        to_field = make_pair(i, j-1);
                        from = field[i][j+1];
                        from_field = make_pair(i, j+1);
                        result.found = true;

                        remove_field = make_pair(i, j);
                    }
                }

                // bottom
                if (pegs[i+1][j] && !pegs[i-1][j]) {
                    if (field[i-1][j] > to || field[i-1][j] == to && to > 0 && field[i+1][j] > from) {
                        to = field[i-1][j];
                        to_field = make_pair(i-1, j);
                        from = field[i+1][j];
                        from_field = make_pair(i+1, j);
                        result.found = true;
                        
                        remove_field = make_pair(i, j);
                    }
                }
            }
        }
    }

    if (result.found) {
        result.to = to_field;
        result.from = from_field;
        result.remove = remove_field;
    }


    return result;
}

void play_the_game() {
    move next_move;

    while (true) {
        next_move = find_next_move();

        if (!next_move.found)
            break;

        // remove peg
        pegs[next_move.remove.first][next_move.remove.second] = false;

        // move peg to new position
        pegs[next_move.from.first][next_move.from.second] = false;
        pegs[next_move.to.first][next_move.to.second] = true;
    }
}

int count_game_result() {
    int result = 0;

    rep(i, 9) {
        rep(j, 9) {
            if (pegs[i][j]) {
                result += field[i][j];
            }
        }
    }

    return result;
}

int main(void) {
    int n, peg;

    cin >> n;

    cout << "HI Q OUTPUT" << endl;

    while (n--) {
        clear_pegs();

        while (cin >> peg) {
            if (peg != 0) {
                set_peg(peg);
                continue;
            }

            play_the_game();
            cout << count_game_result() << endl;

            break;
        }
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
