#include <iostream>
#include <string>
#include <map>
using namespace std;

struct TeamMember {
  int n;
  TeamMember* next;
};

class TeamQueue {
  public:
    TeamQueue(int teams);
    ~TeamQueue();
    void push(int team_member, int team);
    int pop();
  private:
    int teams;
    TeamMember* front;
    TeamMember* back;
    TeamMember** team_tail;
};

TeamQueue::TeamQueue(int teams) {
  this->teams = teams;
  front = NULL;
  back = NULL;
  team_tail = new TeamMember*[teams];
  for (int i = 0; i < teams; i++) {
    team_tail[i] = NULL;
  }
}

TeamQueue::~TeamQueue() {
  TeamMember* tm;
  while (front != NULL) {
    tm = front;
    front = front->next;
    delete tm;
  }
  delete [] team_tail;
}

void TeamQueue::push(int team_member, int team) {
  TeamMember* tm = new TeamMember;
  tm->n = team_member;
  tm->next = NULL;

  if (front == NULL) {
    front = tm;
  }

  if (back == NULL) {
    back = tm;
  }

  if (team_tail[team] == NULL) {
    team_tail[team] = tm;
    back->next = tm;
    back = tm;
  } else {
    if (team_tail[team] == back) {
      back = tm;
    }
    tm->next = team_tail[team]->next;
    team_tail[team]->next = tm;
    team_tail[team] = tm;
  }
}

int TeamQueue::pop() {
  int result = front->n;
  TeamMember* tm = front;
  front = front->next;

  for (int i = 0; i < teams; i++) {
    if (team_tail[i] == tm) {
      team_tail[i] = NULL;
      break;
    }
  }

  if (back == tm) {
    back = NULL;
  }
  
  delete tm;

  return result;
}

int main(void) {
  int teams;
  int n;
  int team_member;
  int scenario = 0;
  string action;

  while (cin >> teams) {
    if (!teams)
      break;

    scenario++;
    map<int,int> team_members; // team number for each team member
    TeamQueue tq(teams);

    for (int i = 0; i < teams; i++) {
      cin >> n;
      while (n--) {
        cin >> team_member;
        team_members[team_member] = i;
      }
    }

    cout << "Scenario #" << scenario << endl;

    while (cin >> action) {
      if (action == "ENQUEUE") {
        cin >> team_member;
        tq.push(team_member, team_members[team_member]);
      } else if (action == "DEQUEUE") {
        cout << tq.pop() << endl;
      } else { // action == STOP
        break;
      }
    }

    cout << endl;
  }

  return 0;
}
