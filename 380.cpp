#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
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

typedef struct _call_forward {
    string target;
    int start;
    int end;
    _call_forward(string target, int start, int end) : target(target), start(start), end(end) {}
} call_forward;

string call_to(map< string, vector<call_forward> >& data, string target, int time) {
    map<string, bool> already_called;
    already_called[target] = true;

    while (true) {
        if (data.find(target) == data.end()) {
            return target;
        }

        bool forwarded = false;

        rep (i, data[target].size()) {
            if (data[target][i].start <= time && data[target][i].end >= time) {
                target = data[target][i].target;
                if (already_called[target]) {
                    return "9999";
                }
                already_called[target] = true;
                forwarded = true;
                break;
            }
        }

        if (!forwarded) return target;
    }

    return "9999";
}

int main(void) {
    int number_of_cases;
    string source, target;
    int start, duration;

    cin >> number_of_cases;

    cout << "CALL FORWARDING OUTPUT" << endl;

    REPI (case_number, 1, number_of_cases) {
        cout << "SYSTEM " << case_number << endl;
        map< string, vector<call_forward> > data;

        while (cin >> source) {
            if (source == "0000") break;

            cin >> start >> duration >> target;

            data[source].push_back(call_forward(target, start, start + duration));
        }

        while (cin >> start) {
            if (start == 9000) break;

            cin >> target;

            string result = call_to(data, target, start);

            printf("AT %04d CALL TO %s RINGS %s\n", start, target.c_str(), result.c_str());
        }
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
