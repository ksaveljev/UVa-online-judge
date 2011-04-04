#include <iostream>
#include <string>
using namespace std;

int main (void) {
   string input;

   while (getline(cin, input)) {
      for (int i = 0; i < input.size(); i++)
         if (input[i] != ' ')
	    input[i] = input[i] - 7;

      cout << input << endl;
   }

   return 0;
}
