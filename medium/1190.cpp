#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') st.push(res.size());
            else if(s[i] == ')') {
                int last = st.top();
                st.pop();
                reverse(res.begin()+last, res.end());
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};