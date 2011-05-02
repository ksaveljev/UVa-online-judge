#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct submit{
  int problem;
  int time;
  char result;
};

struct team {
  int id;
  int solved;
  int time;
  bool submission_made;
  team() : solved(0), time(0), submission_made(false) {}
};

bool theTruthIsOutThere(const team &a, const team &b) {
  if (a.solved == b.solved) {
    if (a.time == b.time) {
      if (a.submission_made == b.submission_made) {
        return a.id < b.id;
      }

      return a.submission_made;
    }

    return a.time < b.time;
  }

  return a.solved > b.solved;
}

int main(void) {
  int cases;
  int contestant;
  submit tmp;
  bool solved_already;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (cases--) {
    team teams[101];
    vector<submit> contestants[101];

    for (int i = 0; i < 101; i++)
      teams[i].id = i;

    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> contestant >> tmp.problem >> tmp.time >> tmp.result;
      //cout << contestant << " " << tmp.problem << " " << tmp.time << " " << tmp.result << endl;
      cin.ignore(100, '\n');

      teams[contestant].submission_made = true;

      if (tmp.result == 'C') {
        solved_already = false;

        for (int i = 0, sz = contestants[contestant].size(); i < sz; i++) {
          if (contestants[contestant][i].problem == tmp.problem && contestants[contestant][i].result == 'C') {
            solved_already = true;
            break;
          }
        }

        if (!solved_already) {
          teams[contestant].time += tmp.time;
          teams[contestant].solved += 1;
          for (int i = 0, sz = contestants[contestant].size(); i < sz; i++) {
            if (contestants[contestant][i].problem == tmp.problem && contestants[contestant][i].result == 'I') {
              teams[contestant].time += 20;
            }
          }
        }
      }

      contestants[contestant].push_back(tmp);
    }

    cin.ignore(100, '\n');

    sort(teams, teams + 101, theTruthIsOutThere);

    //for (int i = 0; i < 101; i++) {
    //  cout << teams[i].id << " " << teams[i].solved << " " << teams[i].time << endl;
    //}

    for (int i = 0; i < 101; i++) {
      if (teams[i].submission_made == false)
        break;

      cout << teams[i].id << " " << teams[i].solved << " " << teams[i].time << endl;
    }

    if (cases)
      cout << endl;
  }

  return 0;
}
