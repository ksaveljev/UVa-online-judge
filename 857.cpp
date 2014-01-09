#include <iostream>
#include <vector>
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

struct message {
    int code;
    int note;
    int m;
    int b;
    int t;
};

int main(void) {
    int n;
    message tmp;

    while (cin >> n) {
        if (n == -1)
            break;

        vector<message> messages;

        rep (i, n) {
            cin >> tmp.code >> tmp.note >> tmp.m >> tmp.b >> tmp.t;
            tmp.t = ((tmp.t + 30) / 60) * 60;
            if (tmp.t == 480) {
                tmp.t = 0;
                tmp.b++;
                if (tmp.b == 5) {
                    tmp.b = 1;
                    tmp.m++;
                }
            }
            messages.push_back(tmp);
        }

        for (vector<message>::iterator i = messages.begin(); i != messages.end(); i++) {
            if (i->code == 0)
                continue;

            for (vector<message>::iterator j = i + 1; j != messages.end(); j++) {
                if (i->note == j->note && i->code == 1 && j->code == 0) {
                    if (i->m == j->m && i->b == j->b && i->t == j->t) {
                        i = messages.erase(i);
                        i--, j--;
                        j = messages.erase(j);
                        j--;
                    }
                    break;
                }
            }
        }

        cout << messages.size() << endl;
        rep (i, messages.size()) {
            cout << messages[i].code << " " << messages[i].note << " " << messages[i].m << " " << messages[i].b << " " << messages[i].t << endl;
        }
    }

    cout << "-1" << endl;

    return 0;
}
