#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> m;
        for(int i : nums) {
            int key = 0;
            int multiplier = 1;
            int temp = i;
            if(i == 0) key = mapping[0];
            while(i > 0) {
                i/=10;
                key += multiplier*mapping[i % 10];
                multiplier*=10;
            }
            m.push_back({key, temp});
        }
        sort(m.begin(), m.end());
        vector<int> res;
        for(auto i : m) {
            res.push_back(nums[i.second]);
        }
        return res;
    }
};

