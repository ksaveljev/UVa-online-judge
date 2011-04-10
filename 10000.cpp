#include <iostream>
#include <vector>
using namespace std;

typedef struct _node {
   int n;
   int length;
   vector<int> adj;
} node;

vector<node> G;
pair<int,int> result;

void dfs(int start, int length) {
   if (G[start-1].length > length)
      return;
   else if (G[start-1].length < length)
      G[start-1].length = length;

   if (G[start-1].adj.size() == 0) {
      if (length > result.first) {
	 result.first = length;
	 result.second = start;
      } else if (length == result.first) {
	 if (start < result.second) {
	    result.second = start;
	 }
      }
   } else {
      for (int i = 0; i < G[start-1].adj.size(); i++) {
	 dfs(G[start-1].adj[i], length + 1);
      }
   }
}

int main (void) {
   int n, start, a, b, counter = 0;
   
   while (cin >> n && n) {
      G.clear();
      counter++;

      for (int i = 1; i <= n; i++) {
	 node N;
	 N.n = i;
	 N.length = 0;
	 G.push_back(N);
      }

      cin >> start;

      while (cin >> a >> b && a && b) {
	 G[a-1].adj.push_back(b);
      }

      result.first = 0;
      result.second = 0;
      dfs(start, 0);

      cout << "Case " << counter << ": The longest path from " << start << " has length " << result.first << ", finishing at " << result.second << "." << endl << endl;
   }


   return 0;
}
