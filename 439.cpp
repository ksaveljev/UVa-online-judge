#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main (void) {
   string b,e;
   pair<int,int> beginning;
   pair<int,int> ending;
   pair< int, pair<int,int> > temp;
   queue< pair< int, pair<int,int> > > q;
   int moves[8][2] = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2} };
   bool visited[8][8];

   while (cin >> b >> e) {
      beginning.second = b[0] - 'a';
      beginning.first = b[1] - '1';
      ending.second = e[0] - 'a';
      ending.first = e[1] - '1';

      while (!q.empty())
         q.pop();

      for (int i = 0; i < 8; i++)
         for (int j = 0; j < 8; j++)
	    visited[i][j] = false;

      int result = 0;
      q.push (pair<int, pair<int,int> >(0, beginning));

      while (!q.empty()) {
         temp = q.front();
	 q.pop();

	 if (temp.second.first == ending.first && temp.second.second == ending.second) {
	    result = temp.first;
	    break;
	 }

	 visited[temp.second.first][temp.second.second] = true;

	 for (int i = 0; i < 8; i++) {
            if (temp.second.first + moves[i][0] >= 0 && temp.second.first + moves[i][0] < 8 && temp.second.second + moves[i][1] >= 0 && temp.second.second + moves[i][1] < 8 && visited[temp.second.first + moves[i][0]][temp.second.second + moves[i][1]] == false) {
	       visited[temp.second.first + moves[i][0]][temp.second.second + moves[i][1]] = true;
               q.push (pair< int, pair<int,int> >(temp.first + 1, pair<int,int>(temp.second.first + moves[i][0], temp.second.second + moves[i][1])));
	    }
	 }
      }

      cout << "To get from " << char(beginning.second + 'a') << char(beginning.first + '1') << " to " << char(ending.second + 'a') << char(ending.first + '1') << " takes " << result << " knight moves." << endl;
   }

   return 0;
}
