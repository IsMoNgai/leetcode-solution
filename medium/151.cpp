#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> process;
        string temp = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') temp += s[i];
            else {
                if(temp != "") process.push_back(temp);
                temp = "";
            }
        }
        if(temp != "") process.push_back(temp);
        reverse(process.begin(), process.end());
        string res = "";
        for(string st : process) {
            res += st;
            res += ' ';
        }
        res.erase(res.size()-1);
        return res;
    }
};