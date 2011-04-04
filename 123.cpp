#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool theTruthIsOutThere(pair< string, pair<int, int> > a, pair< string, pair<int, int> > b) {
   if (a.first < b.first)
      return true;
   else if (a.first == b.first) {
      if (a.second.first < b.second.first)
         return true;
      else if (a.second.first == b.second.first) {
         if (a.second.second < b.second.second)
	    return true;
	 else 
	    return false;
      }
      else
         return false;
   }
   else 
      return false;
}

int main (void) {
   string input;
   vector<string> restricted;
   vector<string> sentences;
   vector< pair<string, pair<int, int> > > words;
   int counter = 0;

   // reading restricted words
   while (cin >> input) {
      if (input == "::")
         break;
      restricted.push_back(input);
   }

   // start main work here
   while (getline(cin, input)) {
      for (int i = 0; i < input.size(); i++)
         input[i] = tolower(input[i]);

      sentences.push_back(input);

      stringstream ss;
      ss << input;

      int c = 0;

      while (ss >> input) {
         bool found = false;
         for (int i = 0; i < restricted.size(); i++) {
            if (restricted[i] == input) {
               found = true;
	       break;
	    }
	 }
	 if (!found)
	    words.push_back(pair< string, pair<int, int> >(input, pair<int,int>(counter, c)));

	 c++;
      }

      counter++;
   }

   sort (words.begin(), words.end(), theTruthIsOutThere);

   for (int i = 0; i < words.size(); i++) {
      stringstream ss;
      ss << sentences[words[i].second.first];
      
      int c = 0;
      while (ss >> input) {
         if (c > 0) cout << " ";
         if (c == words[i].second.second) {
            for (int j = 0; j < input.size(); j++)
	       input[j] = toupper(input[j]);
	    cout << input;
	 } else {
            cout << input;
	 }
	 c++;
      }
      cout << endl;
   }

   return 0;
}
