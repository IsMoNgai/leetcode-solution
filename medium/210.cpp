#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

class Solution {
    public:
    /*

    [[1,0],[1,2],[0,1]]
    adj 
    0 1
    1 0
    2 1

    indegree
    0 0
    1 0
    2 0
    3 2

    queue:
    0 1 2

    */
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            map<int, list<int>> adj;
            vector<int> indegree(numCourses);
            for(auto v : prerequisites) {
                adj[v[1]].push_back(v[0]);
            }

            for(int i = 0; i < numCourses; i++) {
                for(auto e : adj[i]) {
                    indegree[e]++;
                }
            }
            
            queue<int> q;
            vector<int> res;
            for(int i = 0; i < numCourses; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }

            while(!q.empty()) {
                int w = q.front();
                q.pop();

                res.push_back(w);

                for(int i : adj[w]) {
                    if(--indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
            if(res.size() != numCourses) return {};
            return res;
        }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    Solution sol;
    
    vector<int> res = sol.findOrder(numCourses, prerequisites);
    for(int i : res) {
        cout << i << " ";
    }
}