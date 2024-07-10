#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string s : logs) {
            if(s[s.size()-1] == '/' && s[s.size()-2] != '.') {
                ans++;
            }
            else if(s == "../") {
                if(ans > 0) {
                    ans--;
                }
            }
        }
        return ans;
    }
};