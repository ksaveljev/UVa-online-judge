#include <iostream>
using namespace std;

int main (void) {
   int ncoins = 11;
   int coins[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
   double input;
   
   int rows = 6000; // 300 / 0.05;
   double dp[ncoins][rows+1];
   
   for (int i = 0; i < ncoins; i++)
      dp[i][0] = 1;
   
   for (int i = 0; i < rows + 1; i++)
      dp[0][i] = 1;
      
   
   for (int j = 1; j < rows + 1; j++) {
      for (int i = 1; i < ncoins; i++) {
         double a = dp[i-1][j];
         double b = (j - coins[i] < 0) ? 0 : dp[i][j - coins[i]];
         dp[i][j] = a + b;
      }   
   }
   
   while (cin >> input) {
      if (input == 0) break;
      printf("%6.2f%17.0lf\n", input, dp[10][(int)(input*20+0.5)]);
   }

   return 0;   
}
