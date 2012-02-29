#include <iostream>
#include <string>
using namespace std;

int read_slimp(int start, string &s);
int read_slump(int start, string &s);

int read_slimp(int start, string &s) {
    int i = start, sz = s.size();

    if (i == sz)
        return -1;

    if (s[i] == 'A')
        i++;
    else
        return -1;

    if (i == sz)
        return -1;

    if (s[i] == 'H')
        return i + 1;

    if (s[i] == 'B') {
        i = read_slimp(i+1, s);
    } else {
        i = read_slump(i, s);
    }

    if (i == -1 || i == sz)
        return -1;

    if (s[i] == 'C')
        return i + 1;

    return -1;
}

int read_slump(int start, string &s) {
    int i = start, sz = s.size();

    if (i == sz)
        return -1;

    if (s[i] == 'D' || s[i] == 'E')
        i++;
    else
        return -1;

    if (i == sz)
        return -1;

    if (s[i] != 'F')
        return -1;

    for ( ; s[i] == 'F' && i < sz; i++);

    if (i == sz)
        return -1;

    if (s[i] == 'G')
        return i + 1;

    i = read_slump(i, s);

    if (i == -1) 
        return -1;

    return i;
}

bool is_slurpy(string &s) {
    int end = read_slimp(0, s);

    if (end == -1)
        return false;

    end = read_slump(end, s);

    return end == s.size();
}

int main(void) {
    int n;
    string input;

    cin >> n;
    getline(cin, input); // getting \n after n

    cout << "SLURPYS OUTPUT" << endl;

    while (n--) {
        getline(cin, input);
        cout << (is_slurpy(input) ? "YES" : "NO") << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
