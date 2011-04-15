#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct team {
  string name;
  string name_low_case;
  int games_played;
  int wins;
  int ties;
  int losses;
  int points;
  int goals_scored;
  int goals_against;
  team() : games_played(0), wins(0), ties(0), losses(0), points(0), goals_scored(0), goals_against(0) {}
};

struct game_info {
  string team1, team2;
  int goals1, goals2;
};

struct tournament {
  string name;
  int teams_num;
  vector<team> teams;
  void add_game(const game_info &gameinfo);
  void update_team_info(const string &name, int goals_scored, int goals_against);
};

void tournament::add_game(const game_info &gameinfo) {
  update_team_info(gameinfo.team1, gameinfo.goals1, gameinfo.goals2);
  update_team_info(gameinfo.team2, gameinfo.goals2, gameinfo.goals1);
}

void tournament::update_team_info(const string &name, int goals_scored, int goals_against) {
  int index;

  for (int i = 0; i < teams_num; i++) {
    if (teams[i].name == name) {
      index = i;
      break;
    }
  }

  teams[index].games_played++;
  teams[index].goals_scored += goals_scored;
  teams[index].goals_against += goals_against;
  if (goals_scored > goals_against) {
    teams[index].wins++;
    teams[index].points += 3;
  } else if (goals_scored < goals_against) {
    teams[index].losses++;
  } else {
    teams[index].ties++;
    teams[index].points += 1;
  }
}

bool theTruthIsOutThere(const team &a, const team &b) {
  if (a.points != b.points)
    return a.points > b.points;

  if (a.wins != b.wins)
    return a.wins > b.wins;

  if (a.goals_scored - a.goals_against != b.goals_scored - b.goals_against)
    return a.goals_scored - a.goals_against > b.goals_scored - b.goals_against;

  if (a.goals_scored != b.goals_scored)
    return a.goals_scored > b.goals_scored;

  if (a.games_played != b.games_played)
    return a.games_played < b.games_played;

  return a.name_low_case < b.name_low_case;
}

int main(void) {
  int n;
  int games_num;
  string gameinfo;

  cin >> n;
  cin.ignore(1000, '\n');

  while (n--) {
    tournament trn;

    getline(cin, trn.name);

    cin >> trn.teams_num;
    cin.ignore(1000, '\n');

    for (int i = 0; i < trn.teams_num; i++) {
      team tm;
      getline(cin, tm.name);
      tm.name_low_case = tm.name;
      transform(tm.name.begin(), tm.name.end(), tm.name_low_case.begin(), ::toupper);
      trn.teams.push_back(tm);
    }

    cin >> games_num;
    cin.ignore(1000, '\n');

    while (games_num--) {
      game_info gi;
      getline(cin, gi.team1, '#');
      cin >> gi.goals1;
      cin.ignore(10, '@');
      cin >> gi.goals2;
      cin.ignore(10, '#');
      getline(cin, gi.team2);
      trn.add_game(gi);
    }

    sort (trn.teams.begin(), trn.teams.end(), theTruthIsOutThere);

    cout << trn.name << endl;
    for (int i = 0; i < trn.teams_num; i++) {
      cout << i+1 << ") " << trn.teams[i].name << " " << trn.teams[i].points << "p, " << trn.teams[i].games_played << "g (" << trn.teams[i].wins << "-" << trn.teams[i].ties << "-" << trn.teams[i].losses << "), " << trn.teams[i].goals_scored - trn.teams[i].goals_against << "gd (" << trn.teams[i].goals_scored << "-" << trn.teams[i].goals_against << ")" << endl;
    }

    if (n > 0)
      cout << endl;
  }

  return 0;
}
