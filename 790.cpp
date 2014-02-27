#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
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

int time_to_minutes(const string &time);

struct submission {
    int team;
    string problem;
    string time;
    string status;
    
    bool operator<(const submission &s) const {
        int t1 = time_to_minutes(time);
        int t2 = time_to_minutes(s.time);
        if (t1 != t2) return t1 < t2;
        return status < s.status;
    }
};

struct team {
    int num;
    int solved;
    int time;
};

int time_to_minutes(const string &time) {
    int h, m;
    sscanf(time.c_str(), "%d:%d", &h, &m);

    return h * 60 + m;
}

bool theTruthIsOutThere(const team &t1, const team &t2) {
    if (t1.solved > t2.solved) return true;
    if (t1.solved < t2.solved) return false;

    if (t1.time < t2.time) return true;
    if (t1.time > t2.time) return false;

    return t1.num < t2.num;
}

int main(void) {
    int cases;
    team t;
    string input;
    submission tmp;

    cin >> cases;
    cin.ignore(100, '\n');
    getline(cin, input); // blank line

    while (cases--) {
        int max_team = 0;
        vector<submission> submissions;

        while (getline(cin, input)) {
            if (input == "") break;
            istringstream iss(input);
            iss >> tmp.team >> tmp.problem >> tmp.time >> tmp.status;
            submissions.push_back(tmp);

            if (tmp.team > max_team) max_team = tmp.team;
        }

        sort(submissions.begin(), submissions.end());

        vector<team> teams;

        repi (i, max_team) {
            t.num = i;
            t.solved = 0;
            t.time = 0;
            teams.push_back(t);
        }

        map< pair<int,string>, int > attempts;
        map< pair<int,string>, bool> solved;

        rep (i, submissions.size()) {
            pair<int,string> team_problem = make_pair(submissions[i].team, submissions[i].problem);

            if (solved.find(team_problem) != solved.end()) continue;

            if (submissions[i].status == "Y") {
                if (attempts.find(team_problem) != attempts.end()) {
                    teams[submissions[i].team].time += 20 * attempts[team_problem];
                }

                solved[team_problem] = true;
                teams[submissions[i].team].solved += 1;
                teams[submissions[i].team].time += time_to_minutes(submissions[i].time);
            } else {
                if (attempts.find(team_problem) != attempts.end()) {
                    attempts[team_problem] += 1;
                } else {
                    attempts[team_problem] = 1;
                }
            }
        }

        teams.erase(teams.begin()); // we do not need the team with team number 0, it was just a placeholder to make life easier with indexes

        sort (teams.begin(), teams.end(), theTruthIsOutThere);

        int rank = 0;
        cout << "RANK TEAM PRO/SOLVED TIME" << endl;
        rep (i, teams.size()) {
            if (i == 0 || teams[i].solved != teams[i-1].solved || (teams[i].solved == teams[i-1].solved && teams[i].time != teams[i-1].time)) rank = i + 1;
            printf("%4d %4d", rank, teams[i].num);
            if (teams[i].solved > 0) printf(" %4d %10d", teams[i].solved, teams[i].time);
            cout << endl;
        }

        if (cases) cout << endl;
    }

    return 0;
}
