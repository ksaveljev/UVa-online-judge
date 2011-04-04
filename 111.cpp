#include <iostream>
#include <map>
using namespace std;

int main (void) {
   int n, temp;
   map<int,int> order;
   cin >> n;

   int s[n + 1];
   int dp[n + 1];

   for (int i = 0; i < n; i++) {
      cin >> temp;
      order[i+1] = temp;
   }

   while (cin >> temp) {
      s[temp] = 1;
      for (int i = 2; i <= n; i++) {
         cin >> temp;
	 s[temp] = i;
      }

      for (int i = 1; i <= n; i++) {
         s[i] = order[s[i]];
      }

      int maximum = 0;

      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
         dp[i] = 1;
         for (int j = 1; j < i; j++) {
            if (s[i] > s[j]) {
               dp[i] = max(dp[i], dp[j] + 1);
	    }
	 }

	 if (dp[i] > maximum) maximum = dp[i];
      }

      cout << maximum << endl;
   }

   return 0;
}
