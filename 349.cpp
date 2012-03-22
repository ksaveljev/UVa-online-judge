#include <iostream>
#include <queue>
#include <set>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef struct _voter {
    queue<int> votes;
    bool valid;
} voter;


vector<int> start_election(voter voters[100], int number_of_candidates, int number_of_voters, int bad_ballots) {
    vector<int> result;
    bool eliminated[number_of_candidates+1];

    rep(i, number_of_candidates+1) {
        eliminated[i] = false;
    }

    int limit = (number_of_voters - bad_ballots) / 2 + 1;

    while (true) {
        int votes[number_of_candidates + 1];

        rep (i, number_of_candidates+1)
            votes[i] = 0;

        rep (i, number_of_voters) {
            if (!voters[i].valid || voters[i].votes.empty())
                continue;

            votes[voters[i].votes.front()]++;
        }

        int highest = -1;
        int lowest = 10000;
        bool multiple_highest = false;

        REP (i, 1, number_of_candidates+1) {
            if (eliminated[i])
                continue;

            if (votes[i] < lowest) {
                lowest = votes[i];
            }

            if (votes[i] > highest) {
                highest = votes[i];
                multiple_highest = false;
            } else if (votes[i] == highest) {
                multiple_highest = true;
            }
        }

        if (highest >= limit) {
            // find highest
            REP (i, 1, number_of_candidates+1) {
                if (votes[i] == highest) {
                    highest = i;
                    break;
                }
            }

            result.push_back(highest);
            
            break;
        } else if (lowest < highest) {
            // find first lowest and eliminate

            REP (i, 1, number_of_candidates+1) {
                if (!eliminated[i] && votes[i] == lowest) {
                    lowest = i;
                    break;
                }
            }

            eliminated[lowest] = true;

            rep (i, number_of_voters) {
                while (true) {
                    bool e = false;

                    if (!voters[i].votes.empty() && eliminated[voters[i].votes.front()]) {
                        voters[i].votes.pop();
                        e = true;
                    }

                    if (!e)
                        break;
                }
            }
        } else { // lowest == highest
            REP (i, 1, number_of_candidates+1) {
                if (votes[i] == highest) {
                    result.push_back(i);
                }
            }

            break;
        }
    }

    return result;
}

int main(void) {
    int c, n, vote, election_counter = 0;

    while (cin >> c >> n) {
        if (c == 0 && n == 0)
            break;

        election_counter++;

        voter voters[100];
        int bad_ballots = 0;

        rep (i, n) {
            set<int> votes;

            rep (j, c) {
                cin >> vote;
                votes.insert(vote);
                voters[i].votes.push(vote);
            }

            voters[i].valid = (votes.size() == c && *(votes.begin()) == 1 && *(votes.rbegin()) == c ? true : false);

            if (!voters[i].valid)
                bad_ballots++;
        }

        cout << "Election #" << election_counter << endl;

        if (bad_ballots > 0) {
            cout << "   " << bad_ballots << " bad ballot(s)" << endl;
        }

        vector<int> result = start_election(voters, c, n, bad_ballots);

        if (result.size() == 1) {
            cout << "   Candidate " << result[0] << " is elected." << endl;
        } else {
            cout << "   The following candidates are tied:";
            rep (i, result.size()) {
                cout << " " << result[i];
            }
            cout << endl;
        }
    }

    return 0;
}
