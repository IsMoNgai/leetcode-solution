#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int largest = 0;
        for(int i : candies) {
            largest = max(i, largest);
        }
        vector<bool> res;
        for(int i : candies) {
            if(i + extraCandies >= largest) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};