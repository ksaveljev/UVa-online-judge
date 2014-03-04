#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

struct book {
    string title;
    string author;

    bool operator<(const book &other) const {
        if (author != other.author)
            return author < other.author;
        return title < other.title;
    }
};

int main(void) {
    string input;
    char t[85], a[85];
    vector<book> books;
    vector<book> returned;
    map<string,int> position;
    map<int,bool> taken;
    string title;

    while (getline(cin, input)) {
        if (input == "END") break;

        sscanf(input.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
        book tmp;
        tmp.author = string(a);
        tmp.title = string(t);
        books.push_back(tmp);
    }
    
    sort(books.begin(), books.end());

    rep (i, sz(books)) {
        position[books[i].title] = i;
        taken[i] = false;
    }

    while (getline(cin, input)) {
        if (input == "END") break;

        if (input[0] == 'S') { // shelve
            sort(returned.begin(), returned.end());

            rep (i, sz(returned)) {
                int pos = position[returned[i].title];

                bool found = false;
                int after = pos - 1;

                while (after >= 0) {
                    if (taken[after] == false) {
                        found = true;
                        break;
                    }
                    after--;
                }

                if (found) {
                    cout << "Put \"" << books[pos].title << "\" after \"" << books[after].title << "\"" << endl;
                } else {
                    cout << "Put \"" << books[pos].title << "\" first" << endl;
                }

                taken[pos] = false;
            }

            cout << "END" << endl;

            returned.clear();
        } else if (input[0] == 'B') { // borrow
            sscanf(input.c_str(), "BORROW \"%[^\"]\"", t);
            title = string(t);
            int pos = position[title];
            taken[pos] = true;
        } else if (input[0] == 'R') { // return
            sscanf(input.c_str(), "RETURN \"%[^\"]\"", t);
            title = string(t);
            int pos = position[title];
            returned.push_back(books[pos]);
        }
    }

    return 0;
}
