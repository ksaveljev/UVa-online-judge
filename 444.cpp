#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<int,bool> allowed;
vector<int> result;
bool found;

//int reverse_int (int n, int m = 0) {
//   if (n == 0)
//      return m;
//   else
//      return reverse_int (n / 10, m * 10 + n % 10);
//}

string reverse_to_string (int n) {
   stringstream ss;
   while (n > 0) {
      ss << n % 10;
      n /= 10;
   }

   return ss.str();
}

void encode (string& input) {
   for (int i = input.size() - 1; i >= 0; i--) {
      int code = (int)input[i];
      cout << reverse_to_string (code);
   }
   cout << endl;
}

void decode (string& input, int pos = 0) 
{
   if (pos == input.size()) {
      reverse (result.begin(), result.end());
      for (int i = 0; i < result.size(); i++)
         cout << char(result[i]);
      cout << endl;
      found = true;
      return;
   }

   if (pos == input.size() - 1) return;

   int code = input[pos] - '0' + (input[pos+1] - '0') * 10;
  
   if (allowed[code] == true) {
      result.push_back (code);
      decode (input, pos + 2);
      if (found) return;
      result.pop_back();
   }

   if (pos == input.size() - 2) return;

   code = input[pos] - '0' + (input[pos+1] - '0') * 10 + (input[pos+2] - '0') * 100;

   if (allowed[code] == true) {
      result.push_back (code);
      decode (input, pos + 3);
      if (found) return;
      result.pop_back();
   }
}

int main (void) {
   string input;

   for (char i = 'a'; i <= 'z'; i++)
      allowed.insert (pair<int,bool>(int(i), true));
   for (char i = 'A'; i <= 'Z'; i++)
      allowed.insert (pair<int,bool>(int(i), true));

   allowed.insert (pair<int,bool>(int(' '), true));
   allowed.insert (pair<int,bool>(int('!'), true));
   allowed.insert (pair<int,bool>(int(','), true));
   allowed.insert (pair<int,bool>(int('.'), true));
   allowed.insert (pair<int,bool>(int(':'), true));
   allowed.insert (pair<int,bool>(int(';'), true));
   allowed.insert (pair<int,bool>(int('?'), true));


   while (getline(cin, input)) {
      result.clear();
      found = false;
      if (input[0] >= '0' && input[0] <= '9')
         decode (input);
      else
         encode (input);
   }

   return 0;
}
