#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> g;
        vector<int> res;
        for(int i : nums2) {
            g[i]++;
        }
        for(int n : nums1) {
            if(g[n] > 0) {
                res.push_back(n);
                g[n]--;
            }
        }
        return res;
    }
};