#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

typedef struct _player {
    int n;
    string name;
    char pos;
    int years;
} player;

bool theTruthIsOutThere(const player &a, const player &b) {
    return a.n < b.n;
}

int main(void) {
    bool finish = false;
    string input;
    player p;
    vector<player> def, str, mid, gk, team;
    vector<int> y;

    while (true) {
        def.clear();
        str.clear();
        mid.clear();
        gk.clear();
        team.clear();

        for (int i = 0; i < 22; i++) {
            cin >> p.n;

            if (p.n == 0) {
                finish = true;
                break;
            }

            cin >> p.name >> p.pos;
            getline(cin, input); // information regarding years played for the club

            for (int j = 0, sz = input.size(); j < sz; j++) {
                if (input[j] >= '0' && input[j] <= '9' || input[j] == ' ')
                    continue;
                input[j] = ' ';
            }

            y.clear();
            istringstream iss(input);
            copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter< vector<int> >(y));

            p.years = 0;
            for (int j = 1, sz = y.size(); j < sz; j+=2) {
                p.years += y[j] - y[j-1] + 1;
            }

            switch (p.pos) {
                case 'G':
                    gk.push_back(p);
                    break;
                case 'D':
                    def.push_back(p);
                    break;
                case 'M':
                    mid.push_back(p);
                    break;
                case 'S':
                    str.push_back(p);
                    break;
            }
        }

        if (finish)
            break;

        char tmp;
        int defenders, midplayers, strikers;

        cin >> defenders >> tmp >> midplayers >> tmp >> strikers;

        if (defenders > def.size() || midplayers > mid.size() || strikers > str.size() || 1 > gk.size()) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
            cout << endl;
            continue;
        }

        sort(gk.begin(), gk.end(), theTruthIsOutThere);
        sort(def.begin(), def.end(), theTruthIsOutThere);
        sort(mid.begin(), mid.end(), theTruthIsOutThere);
        sort(str.begin(), str.end(), theTruthIsOutThere);

        player captain;
        team.push_back(gk[0]);
        for (int i = 0; i < defenders; i++)
            team.push_back(def[i]);
        for (int i = 0; i < midplayers; i++)
            team.push_back(mid[i]);
        for (int i = 0; i < strikers; i++)
            team.push_back(str[i]);

        int best = -1;
        for (int i = 0; i < 11; i++) {
            if (team[i].years > best) {
                best = team[i].years;
                captain = team[i];
            } else if (team[i].years == best) {
                if (team[i].n > captain.n) {
                    captain = team[i];
                }
            }
        }

        cout << captain.n << " " << captain.name << " " << captain.pos << endl;
        for (int i = 0; i < 11; i++) {
            if (team[i].n == captain.n)
                continue;

            cout << team[i].n << " " << team[i].name << " " << team[i].pos << endl;
        }

        cout << endl;
    }

    return 0;
}
