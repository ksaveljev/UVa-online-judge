#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t;
    string input;

    cin >> t;

    cin.ignore(100, '\n');

    rep (case_number, t) {
        getline (cin, input);

        int memory[100];
        int pointer = 0;

        rep (i, 100)
            memory[i] = 0;

        rep (i, input.size()) {
            switch (input[i]) {
                case '>':
                    pointer++;
                    if (pointer == 100)
                        pointer = 0;
                    break;
                case '<':
                    pointer--;
                    if (pointer == -1)
                        pointer = 99;
                    break;
                case '+':
                    memory[pointer]++;
                    if (memory[pointer] == 256)
                        memory[pointer] = 0;
                    break;
                case '-':
                    memory[pointer]--;
                    if (memory[pointer] == -1)
                        memory[pointer] = 255;
                    break;
                case '.':
                    break;
            }
        }

        cout << "Case " << case_number + 1 << ":";

        rep (i, 100) {
            printf(" %02X", memory[i]);
        }

        cout << endl;
    }

    return 0;
}
