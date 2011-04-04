#include <iostream>
#include <iomanip>
using namespace std;

int main (void) {
   int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
   int n;
   int res[25];

   while (cin >> n) {
      if (n == 0) break;
      
      memset(res, 0, sizeof(int) * 25);
      
      for (int i = 2; i <= n; i++) {
         int temp = i;
	 for (int j = 0; j < 25; j++) {
            if (primes[j] > i) break;

	    while (temp % primes[j] == 0) {
               temp /= primes[j];
	       res[j]++;
	    }
	 }
      }

      int max = 0;
      for (int i = 0; i < 25; i++) {
         if (res[i] > 0) max = i;
      }


      cout << setw(3) << n << "! =";
      for (int i = 0; i <= max; i++) {
         if (i > 0 && i % 15 == 0) cout << endl << "      ";
         cout << setw(3) << res[i];
      }
      cout << endl;
   }

   return 0;
}
