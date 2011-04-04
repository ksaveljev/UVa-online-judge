#include <iostream>
#include <stdlib.h>
using namespace std;

int main (void) {
   int n;
   int coins[] = {1, 5, 10, 25, 50};
   int maximum = 30000;
   unsigned long long **dp;

   dp = (unsigned long long**)malloc(sizeof(unsigned long long*)*5);
   for (int i = 0; i < 5; i++)
      dp[i] = (unsigned long long*)malloc(sizeof(unsigned long long)*(maximum+1));
   
   //unsigned long long dp[5][maximum+1];

   for (int i = 0; i < 5; i++) 
      dp[i][0] = 1;

   for (int i = 0; i <= maximum; i++)
      dp[0][i] = 1;


   for (int i = 1; i <= maximum; i++) {
      for (int j = 1; j < 5; j++) {
         unsigned long long a = dp[j-1][i];
	 unsigned long long b = (i - coins[j] < 0) ? 0 : dp[j][i - coins[j]];
         dp[j][i] = a + b;
      }
   }


   while (cin >> n) {
      if (dp[4][n] > 1) {
         cout << "There are " << dp[4][n] << " ways to produce " << n << " cents change." << endl;
      } else {
         cout << "There is only 1 way to produce " << n << " cents change." << endl;
      }
   }


   for (int i = 4; i >= 0; i--)
      free(dp[i]);

   free(dp);

   return 0;
}
