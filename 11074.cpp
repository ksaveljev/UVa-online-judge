#include <iostream>
using namespace std;

void draw_wall(int t) {
    for (int i = 0; i < t; i++)
        cout << "*";
}

void draw_cell(int s) {
    for (int i = 0; i < s; i++)
        cout << ".";
}

void draw_cells(int t, int s, int n) {
    for (int i = 0; i < s; i++) {
        draw_wall(t);

        for (int j = 0; j < n; j++) {
            draw_cell(s);
            draw_wall(t);
        }
        cout << endl;
    }
}

void draw_separator(int t, int s, int n) {
    int len = (n + 1) * t + n * s;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < len; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main(void) {
    int s, t, n;
    int casenum = 0;

    while (cin >> s >> t >> n) {
        if (s == 0 && t == 0 && n == 0)
            break;

        casenum++;

        cout << "Case " << casenum << ":" << endl;

        draw_separator(t, s, n);

        for (int i = 0; i < n; i++) {
            draw_cells(t, s, n);
            draw_separator(t, s, n);
        }

        cout << endl;
    }

    return 0;
}
