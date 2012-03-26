#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int n;
char var[8];
int identation_size = 1;

void print_vars() {
    rep (i, n) {
        if (i)
            cout << ",";

        cout << var[i];
    }
}

void ident() {
    rep (i, identation_size)
        cout << "  ";
}

void initialize() {
    rep (i, n)
        var[i] = 'a' + i;

    cout << "program sort(input,output);" << endl;
    cout << "var" << endl;

    print_vars(); // no endl

    cout << " : integer;" << endl;
    cout << "begin" << endl;
    cout << "  readln(";

    print_vars(); // no endl

    cout << ");" << endl;
}

void construct(int i, int j) {
    if (j == -1) {
        return construct (i + 1, i);
    }

    if (i == n) {
        ident();
        cout << "writeln(";
        print_vars();
        cout << ")" << endl;
        return;
    }

    ident();
    cout << "if " << var[j+1] << " < " << var[j] << " then" << endl;
    swap (var[j], var[j+1]);
    identation_size++;
    construct (i, j - 1);
    identation_size--;
    swap (var[j], var[j+1]);
    ident();
    cout << "else" << endl;
    identation_size++;
    construct (i + 1, i);
    identation_size--;
}

void finish() {
    cout << "end." << endl;
}

int main(void) {
    int t;

    cin >> t;

    while (t--) {
        cin >> n;

        initialize();

        construct(1, 0);

        finish();

        if (t)
            cout << endl;
    }

    return 0;
}
