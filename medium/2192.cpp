#include <iostream>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(int n, int v, map<int, list<int>> &adj, set<int> &visited, set<int> &ancestor) {
        visited.insert(v);

        for(int neighbour : adj[v]) {
            if(visited.count(neighbour) == 0) {
                dfs(n, neighbour, adj, visited, ancestor);
            }
            ancestor.insert(neighbour);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //reverse adj
        //loop:
        //dfs with memo (ancestors set)
        //sort set

        vector<vector<int>> res;
        map<int, list<int>> adj;

        for(auto v : edges) {
            adj[v[1]].push_back(v[0]);
        }

        for(int i = 0; i < n; i++) {
            set<int> visited;
            set<int> ancestor;
            dfs(n, i, adj, visited, ancestor);
            vector<int> temp(ancestor.begin(), ancestor.end());
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }

        return res;
    }
};