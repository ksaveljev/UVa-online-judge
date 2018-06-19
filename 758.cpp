#include <iostream>
#include <queue>
using namespace std;

char field[10][15];
bool visited[10][15];

void print_field() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void drop_down() {
    for (int i = 0; i < 15; i++) {
        bool dropped;
        do {
            dropped = false;
            for (int j = 9; j >= 1; j--) {
                if (field[j][i] == ' ' && field[j-1][i] != ' ') {
                    field[j][i] = field[j-1][i];
                    field[j-1][i] = ' ';
                    dropped = true;
                }
            }
        } while (dropped);
    }
}

void shift_left() {
    bool shifted;

    do {
        shifted = false;

        for (int c = 1; c < 15; c++) {
            bool current_empty = true;
            bool previous_empty = true;
            for (int r = 0; r < 10; r++) {
                if (field[r][c-1] != ' ') {
                    previous_empty = false;
                    break;
                }
                if (field[r][c] != ' ') {
                    current_empty = false;
                }
            }

            if (previous_empty && !current_empty) {
                for (int r = 0; r < 10; r++) {
                    field[r][c-1] = field[r][c];
                    field[r][c] = ' ';
                }
                shifted = true;
            }
        }
    } while (shifted);
}

typedef struct next_move_ {
    char c;
    int num;
    int score;
    pair<int,int> coords;
} next_move;

next_move find_next() {
    next_move best;

    best.c = ' ';
    best.num = 0;
    best.score = 0;
    best.coords = make_pair(-1,-1);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            visited[i][j] = false;

    pair<int,int> tmp;
    queue< pair<int,int> > q;

    for (int c = 0; c < 15; c++) {
        for (int r = 9; r >= 0; r--) {
            if (!visited[r][c] && field[r][c] != ' ') {

                char ch = field[r][c];
                int counter = 0;

                visited[r][c] = true;
                q.push(make_pair(r, c));

                while (!q.empty()) {
                    tmp = q.front();
                    q.pop();

                    counter++;

                    if (tmp.first > 0 && !visited[tmp.first-1][tmp.second] && field[tmp.first-1][tmp.second] == ch) {
                        visited[tmp.first-1][tmp.second] = true;
                        q.push(make_pair(tmp.first-1, tmp.second));
                    }
                    if (tmp.first < 9 && !visited[tmp.first+1][tmp.second] && field[tmp.first+1][tmp.second] == ch) {
                        visited[tmp.first+1][tmp.second] = true;
                        q.push(make_pair(tmp.first+1, tmp.second));
                    }
                    if (tmp.second > 0 && !visited[tmp.first][tmp.second-1] && field[tmp.first][tmp.second-1] == ch) {
                        visited[tmp.first][tmp.second-1] = true;
                        q.push(make_pair(tmp.first, tmp.second-1));
                    }
                    if (tmp.second < 14 && !visited[tmp.first][tmp.second+1] && field[tmp.first][tmp.second+1] == ch) {
                        visited[tmp.first][tmp.second+1] = true;
                        q.push(make_pair(tmp.first, tmp.second+1));
                    }
                }

                if (counter > best.num) {
                    best.c = ch;
                    best.num = counter;
                    best.score = (counter - 2) * (counter - 2);
                    best.coords = make_pair(r, c);
                }
            }
        }
    }

    return best;
}

void make_move(next_move move) {
    queue< pair<int,int> > q;
    pair<int,int> tmp;

    q.push(move.coords);
    field[move.coords.first][move.coords.second] = ' ';

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.first > 0 && field[tmp.first-1][tmp.second] == move.c) {
            field[tmp.first-1][tmp.second] = ' ';
            q.push(make_pair(tmp.first-1, tmp.second));
        }
        if (tmp.first < 9 && field[tmp.first+1][tmp.second] == move.c) {
            field[tmp.first+1][tmp.second] = ' ';
            q.push(make_pair(tmp.first+1, tmp.second));
        }
        if (tmp.second > 0 && field[tmp.first][tmp.second-1] == move.c) {
            field[tmp.first][tmp.second-1] = ' ';
            q.push(make_pair(tmp.first, tmp.second-1));
        }
        if (tmp.second < 14 && field[tmp.first][tmp.second+1] == move.c) {
            field[tmp.first][tmp.second+1] = ' ';
            q.push(make_pair(tmp.first, tmp.second+1));
        }
    }

    //print_field();
    drop_down();
    //print_field();
    shift_left();
    //print_field();
}

int main(void) {
    int n, counter = 0;

    cin >> n;

    while (n--) {
        counter++;
        if (counter > 1) cout << endl;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 15; j++) {
                cin >> field[i][j];
            }
        }

        //print_field();

        cout << "Game " << counter << ":" << endl;
        cout << endl;
        int total_score = 0;
        int total_balls = 10 * 15;
        int moves = 0;
        while (true) {
            next_move move = find_next();

            if (move.coords.first == -1 && move.coords.second == -1) {
                break;
            }

            if (move.num < 2) break;

            moves++;
            total_score += move.score;
            total_balls -= move.num;

            cout << "Move " << moves << " at (" << (10 - move.coords.first) << "," << (move.coords.second + 1) << "): removed " << move.num << " balls of color " << move.c << ", got " << move.score << " points." << endl;

            make_move(move);
        }

        if (total_balls == 0) total_score += 1000;

        cout << "Final score: " << total_score << ", with " << total_balls << " balls remaining." << endl;
    }

    return 0;
}
