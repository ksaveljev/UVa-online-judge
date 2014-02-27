#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdio>
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

struct team {
    string name;
    int points, games, scored, suffered, diff;
};

bool compare_names(const string &n1, const string &n2) {
    int i = 0;
    while (i < n1.size() && i < n2.size()) {
        if (tolower(n1[i]) != tolower(n2[i])) {
            return tolower(n1[i]) < tolower(n2[i]);
        }
        i++;
    }

    return n1.size() < n2.size();
}

bool theTruthIsOutThere(const team &t1, const team &t2) {
    if (t1.games == 0 && t2.games == 0) return compare_names(t1.name, t2.name);

    if (t1.points != t2.points) return t1.points > t2.points;
    if (t1.diff != t2.diff) return t1.diff > t2.diff;
    if (t1.scored != t2.scored) return t1.scored > t2.scored;

    return compare_names(t1.name, t2.name);
}

void add_stats(vector<team> &teams, string name, int scored, int suffered) {
    int team_index;

    rep (i, teams.size()) {
        if (teams[i].name == name) {
            team_index = i;
            break;
        }
    }

    if (scored > suffered) teams[team_index].points += 3;
    else if (scored == suffered) teams[team_index].points += 1;

    teams[team_index].games += 1;
    teams[team_index].scored += scored;
    teams[team_index].suffered += suffered;
    teams[team_index].diff += scored - suffered;
}

int main(void) {
    int T, G;
    team tmp;
    string input, t1, t2;
    int s1, s2;
    bool first = true;

    while (cin >> T >> G) {
        if (T == 0 && G == 0) break;
        cin.ignore(100, '\n');

        if (first) first = false; else cout << endl;

        vector<team> teams;

        while (T--) {
            getline(cin, input);
            tmp.name = input;
            tmp.points = tmp.games = tmp.scored = tmp.suffered = tmp.diff = 0;
            teams.push_back(tmp);
        }

        while (G--) {
            cin >> t1 >> s1 >> input >> s2 >> t2;

            add_stats(teams, t1, s1, s2);
            add_stats(teams, t2, s2, s1);
        }

        sort (teams.begin(), teams.end(), theTruthIsOutThere);

        int rank = 0;

        rep (i, teams.size()) {
            if (i == 0 || teams[i].points != teams[i-1].points || teams[i].diff != teams[i-1].diff || teams[i].scored != teams[i-1].scored) {
                rank = i + 1;
                printf("%2d. ", rank);
            } else {
                printf("    ");
            }

            printf("%15s %3d %3d %3d %3d %3d ", teams[i].name.c_str(), teams[i].points, teams[i].games, teams[i].scored, teams[i].suffered, teams[i].diff);

            if (teams[i].games == 0) printf("%6s\n", "N/A");
            else printf("%6.2f\n", teams[i].points * 100.0 / (3.0 * teams[i].games) + 1e-9);
        }
    }

    return 0;
}
