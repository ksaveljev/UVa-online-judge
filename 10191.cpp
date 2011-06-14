#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
  return a.first < b.first;
}

string time2str(int time) {
  char buffer[50];
  sprintf(buffer, "%02d:%02d", time / 60, time % 60);
  return string(buffer);
}

string duration2str(int duration) {
  char buffer[50];

  if (duration < 60)
    sprintf(buffer, "%d minutes", duration);
  else
    sprintf(buffer, "%d hours and %d minutes", duration / 60, duration % 60);
  
  return string(buffer);
}

int main(void) {
  int n;
  int h, m;
  char c;
  int time1, time2;
  int day = 0;
  int lowest, highest;

  while (cin >> n) {
    day++;

    vector< pair<int,int> > v;

    lowest = 18 * 60;
    highest = 10 * 60;

    while (n--) {
      cin >> h >> c >> m;
      time1 = 60 * h + m;
      cin >> h >> c >> m;
      time2 = 60 * h + m;
      cin.ignore(1000, '\n');

      if (time1 < lowest)
        lowest = time1;

      if (time2 > highest)
        highest = time2;

      v.push_back(make_pair(time1, time2));
    }

    if (lowest != 10 * 60)
      v.push_back(make_pair(10*60, 10*60));

    if (highest != 18 * 60)
      v.push_back(make_pair(18*60, 18*60));

    sort(v.begin(), v.end(), theTruthIsOutThere);

    pair<int,int> result; // start + length
    result.second = 0;

    for (int i = 1, sz = v.size(); i < sz; i++) {
      if (v[i].first - v[i-1].second > result.second) {
        result.first = v[i-1].second;
        result.second = v[i].first - v[i-1].second;
      }
    }

    cout << "Day #" << day << ": the longest nap starts at " << time2str(result.first) << " and will last for " << duration2str(result.second) << "." << endl;
  }

  return 0;
}
