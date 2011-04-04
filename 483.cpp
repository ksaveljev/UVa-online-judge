#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main (void) {
   string input;

   while (getline(cin, input)) {
      stringstream ss;
      ss << input;

      int c = 0;
      while (ss >> input) {
         if (c > 0) cout << " ";
         for (int i = input.size() - 1; i >= 0; i--)
	    cout << input[i];
	 c++;
      }
      cout << endl;
   }
}
