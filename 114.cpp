#include <iostream>
#include <map>
using namespace std;

int main(void)
{
  int m, n, wall_hit_cost, p, v, c, x, y, direction, lifetime;
  map< pair<int,int>, pair<int,int> > bumpers;
  int total_points = 0;

  cin >> m >> n >> wall_hit_cost >> p;

  while (p--) {
    cin >> x >> y >> v >> c;
    bumpers[make_pair(x, y)] = make_pair(v, c);
  }

  while (cin >> x >> y >> direction >> lifetime) {
    int points = 0;

    while (--lifetime > 0) { // for every move we lose 1 lifetime point
      switch(direction) {
        // right
        case 0:
          if (x == m - 1) {
            lifetime -= wall_hit_cost;
            direction = 3;
          } else {
            if (bumpers.find(make_pair(x+1,y)) != bumpers.end()) {
              points += bumpers[make_pair(x+1,y)].first;
              lifetime -= bumpers[make_pair(x+1,y)].second;
              direction = 3;
            } else {
              x++;
            }
          }
          break;
        // up
        case 1:
          if (y == n - 1) {
            lifetime -= wall_hit_cost;
            direction = 0;
          } else {
            if (bumpers.find(make_pair(x,y+1)) != bumpers.end()) {
              points += bumpers[make_pair(x,y+1)].first;
              lifetime -= bumpers[make_pair(x,y+1)].second;
              direction = 0;
            } else {
              y++;
            }
          }
          break;
        // left
        case 2:
          if (x == 2) {
            lifetime -= wall_hit_cost;
            direction = 1;
          } else {
            if (bumpers.find(make_pair(x-1,y)) != bumpers.end()) {
              points += bumpers[make_pair(x-1,y)].first;
              lifetime -= bumpers[make_pair(x-1,y)].second;
              direction = 1;
            } else {
              x--;
            }
          }
          break;
        // down
        case 3:
          if (y == 2) {
            lifetime -= wall_hit_cost;
            direction = 2;
          } else {
            if (bumpers.find(make_pair(x,y-1)) != bumpers.end()) {
              points += bumpers[make_pair(x,y-1)].first;
              lifetime -= bumpers[make_pair(x,y-1)].second;
              direction = 2;
            } else {
              y--;
            }
          }
          break;
      }
    }

    cout << points << endl;
    total_points += points;
  }
  
  cout << total_points << endl;
  
  return 0;
}
