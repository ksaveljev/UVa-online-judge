#include <iostream>
#include <string>
#include <vector>
using namespace std;

char decode_vigenere(char decoded, char encoded) {
    int a = 'z' - decoded;
    int b = encoded - 'A';

    return char('A' + (b + a) % 26);
}

int main(void) {
    bool first = true;
    string input;
    string nums[10] = {"nine", "eight", "seven", "six", "five", "four", "three", "two", "one", "zero"};
    vector<string> numbers;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                numbers.push_back(nums[i] + nums[j] + nums[k]);

    while (getline(cin, input)) {
        if (!first)
            cout << endl;
        first = false;

        for (int i = 0, sz = numbers.size(); i < sz; i++) {
            if (numbers[i].size() != input.size())
                continue;

            for (int j = 0; j < numbers[i].size(); j++) {
                cout << decode_vigenere(numbers[i][j], input[j]);
            }
            cout << " -> " << numbers[i] << endl;
        }
    }

    return 0;
}
