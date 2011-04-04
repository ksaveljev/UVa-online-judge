#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool theTruthIsOutThere(pair<string,string> a, pair<string,string> b) {
   if (a.second < b.second)
      return true;
   else 
      return false;
}

int main (void) {
   string input;
   vector< pair<string,string> > words;
   vector<string> result;

   while (getline(cin, input)) {
      if (input == "#") break;

      stringstream ss;
      ss << input;

      while (ss >> input) {
         string temp(input);

	 for (int i = 0; i < temp.size(); i++)
	    if (temp[i] >= 'A' && temp[i] <= 'Z')
	       temp[i] = tolower(temp[i]);

	 sort (temp.begin(), temp.end());

	 words.push_back(pair<string,string>(input, temp));
      }
   }

   sort (words.begin(), words.end(), theTruthIsOutThere);

   bool bad = false;
   for (int i = 0; i < words.size() - 1; i++) {
      if (words[i].second != words[i+1].second) {
         if (bad) {
            bad = false;
	 } else {
            result.push_back(words[i].first);
	 }
      } else {
         bad = true;
      }
   }

   if (!bad) result.push_back(words[words.size()-1].first);

   sort (result.begin(), result.end());

   for (int i = 0; i < result.size(); i++) 
      cout << result[i] << endl;

   return 0;
}
