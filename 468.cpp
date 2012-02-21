#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool theTruthIsOutThere(const pair<char,int> &a, const pair<char,int> &b) {
  return a.second > b.second;
}

int main(void)
{
  int cases;
  string input, encoded, decoded;

  cin >> cases;

  // \n after cases
  getline(cin, input);

  while (cases--) {
    // blank line
    getline(cin, input);

    getline(cin, decoded);
    getline(cin, encoded);

    input = encoded;

    sort(decoded.begin(), decoded.end());
    sort(encoded.begin(), encoded.end());

    vector< pair<char,int> > decoded_occurrences;
    vector< pair<char,int> > encoded_occurrences;

    int count = 1;
    for (int i = 1, sz = decoded.size(); i < sz; i++) {
      if (decoded[i] == decoded[i-1]) {
        count++;
      } else {
        if (decoded[i-1] >= 'a' && decoded[i-1] <= 'z' || decoded[i-1] >= 'A' && decoded[i-1] <= 'Z') {
          decoded_occurrences.push_back(make_pair(decoded[i-1], count));
        }
        count = 1;
      }
    }
    if (decoded[decoded.size()-1] >= 'a' && decoded[decoded.size()-1] <= 'z' || decoded[decoded.size()-1] >= 'A' && decoded[decoded.size()-1] <= 'Z') {
      decoded_occurrences.push_back(make_pair(decoded[decoded.size()-1], count));
    }

    count = 1;
    for (int i = 0, sz = encoded.size(); i < sz; i++) {
      if (encoded[i] == encoded[i-1]) {
        count++;
      } else {
        if (encoded[i-1] >= 'a' && encoded[i-1] <= 'z' || encoded[i-1] >= 'A' && encoded[i-1] <= 'Z') {
          encoded_occurrences.push_back(make_pair(encoded[i-1], count));
        }
        count = 1;
      }
    }
    if (encoded[encoded.size()-1] >= 'a' && encoded[encoded.size()-1] <= 'z' || encoded[encoded.size()-1] >= 'A' && encoded[encoded.size()-1] <= 'Z') {
      encoded_occurrences.push_back(make_pair(encoded[encoded.size()-1], count));
    }

    sort(decoded_occurrences.begin(), decoded_occurrences.end(), theTruthIsOutThere);
    sort(encoded_occurrences.begin(), encoded_occurrences.end(), theTruthIsOutThere);

    map<char,char> decoder;
    for (int i = 0, sz = encoded_occurrences.size(); i < sz; i++) {
      decoder[encoded_occurrences[i].first] = decoded_occurrences[i].first;
    }

    for (int i = 0, sz = input.size(); i < sz; i++) {
      cout << decoder[input[i]];
    }
    cout << endl;

    if (cases) {
      cout << endl;
    }
  }
  
  return 0;
}
