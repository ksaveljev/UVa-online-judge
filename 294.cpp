#include <iostream>
#include <math.h>
using namespace std;

int main (void) {
   int n;
   unsigned long long a, b;

   cin >> n;

   while (n--) {
      cin >> a >> b;
      pair<unsigned long long, int> best;

      best.first = best.second = 0;

      for (unsigned long long i = a; i <= b; i++) {
         int count = 0;
         unsigned long long temp = sqrt(i);

	 for (unsigned long long j = 1; j <= temp; j++) {
            if (i % j == 0) count++;
	 }

         count *= 2;
	 if (temp * temp == i) --count;

	 if (count > best.second) {
            best.first = i;
	    best.second = count;
	 }
      }

      cout << "Between " << a << " and " << b << ", " << best.first << " has a maximum of " << best.second << " divisors." << endl;
   }

   return 0;
}
