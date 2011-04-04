#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main (void) {
   int round;
   string correct;
   string taken;
   map<char,bool> alph;

   while (cin >> round) {
      if (round == -1) break;

      alph.clear();
      cin >> correct >> taken;

      int wrong = 0;

      for (int i = 0; i < taken.size(); i++) {
         if (alph[taken[i]] == false) {
            alph[taken[i]] = true;

            bool found = false;
	    for (int j = 0; j < correct.size(); j++) {
               if (correct[j] == taken[i]) {
                  found = true;
		  correct[j] = '*';
	       }
	    }

	    if (!found) {
               ++wrong;

	       if (wrong == 7)
	          break;
	    }
	 }
      }

      cout << "Round " << round << endl;

      if (wrong == 7) {
         cout << "You lose." << endl;
      } else {
         bool ok = true;
         for (int i = 0; i < correct.size(); i++) {
            if (correct[i] != '*') {
	       ok = false;
               cout << "You chickened out." << endl;
	       break;
	    }
	 }

         if (ok)
	    cout << "You win." << endl;
      }
   }

   return 0;
}
