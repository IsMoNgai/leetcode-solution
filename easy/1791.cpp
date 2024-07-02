#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> g;
        for(auto e : edges) {
            for(int i : e) {
                g[i]++;
            }
        }
        for(auto i : g) {
            if(i.second == edges.size()) return i.first;
        }
        return 0;
    }
};