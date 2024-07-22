#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> pos;
        string res = s;
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(vowel.find(s[i]) != vowel.end()) {
                pos.push_back(i);
                temp += s[i];
            }
        }
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < pos.size(); i++) {
            res[pos[i]] = temp[i];
        }
        return res;
    }
};

// leetcode
// 01234567

// 1257
// 7521
// eoee
