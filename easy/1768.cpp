#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        for(int i = 0; i < min(word1.size(), word2.size()); i++) {
            ans += word1[i];
            ans += word2[i];
        }
        if(2*word1.size() == ans.size()) ans.append(word2.substr(word1.size()));
        else ans.append(word1.substr(word2.size()));
        return ans;
    }
};