#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> order = positions;
        sort(order.begin(), order.end());
        map<int, int> m;
        for(int i = 0; i < positions.size(); i++) {
            m[positions[i]] = i;
        }
        stack<int> s;
        for(int i : order) {
            if(directions[m[i]] == 'R') {
                s.push(i);
            } else {
                while(!s.empty() && healths[m[i]] > 0) {
                    //if left > right
                    //if left < right
                    //if left == right
                    int stackItem = s.top();
                    s.pop();
                    if(healths[m[i]] > healths[m[stackItem]]) {
                        healths[m[i]]--;
                        healths[m[stackItem]] = 0;
                    } else if(healths[m[i]] < healths[m[stackItem]]) {
                        healths[m[i]] = 0;
                        healths[m[stackItem]]--;
                        s.push(stackItem);
                    } else {
                        healths[m[i]] = 0;
                        healths[m[stackItem]] = 0;
                    }
                }
            }
        }
        vector<int> res;
        for(int i : healths) {
            if(i > 0) res.push_back(i);
        }
        return res;
    }
};