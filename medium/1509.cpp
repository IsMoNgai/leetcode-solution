#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        std::sort(nums.begin(), nums.end());

        int m = INT_MAX;
        for(int l = 0; l < 4; l++) {
            int r = nums.size()-3-1+l;
            m = min(nums[r]-nums[l], m);
        }

        return m;
    }
};