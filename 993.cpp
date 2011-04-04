#include <iostream>
#include <vector>
using namespace std;

int main (void) {
   int n, a;
   vector<int> result;

   cin >> a;

   while (a--) {
      cin >> n;
      if (n == 1) { cout << 1 << endl; continue; }


      result.clear();

      for (int i = 9; i >= 2; i--) {
         while (n % i == 0) {
            result.push_back (i);
	    n /= i;
	 }
      }

      if (n > 9) cout << "-1" << endl;
      else {
         sort (result.begin(), result.end());
	 for (int i = 0; i < result.size(); i++)
	    cout << result[i];
	 cout << endl;
      }
   }

   return 0;
}
