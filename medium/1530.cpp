#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void leafNode(TreeNode* root, set<TreeNode*>& leaf) {
        if(!root) return;
        if(!root->left && !root->right) {
            leaf.insert(root);
        }
        leafNode(root->left, leaf);
        leafNode(root->right, leaf);
    }
    void treeToAdj(TreeNode* root, map<TreeNode*, vector<TreeNode*>>& adj) {
        if(!root) return;
        if(root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        if(root->right) {
            adj[root->right].push_back(root);
            adj[root].push_back(root->right);
        }
        treeToAdj(root->left, adj);
        treeToAdj(root->right, adj);

    }
    int countPairs(TreeNode* root, int distance) {
        /*
        thinking process:

        find all leafnode firsts
        convert tree to graph
        traverse graph
        dfs all leafnode terminate when step > distance
        a smart way to count distance is puting pair<Tree, int> into stack instead
        reachable leafnode = +1 res
        */
        set<TreeNode*> leaf;
        map<TreeNode*, vector<TreeNode*>> adj;
        leafNode(root, leaf);
        treeToAdj(root, adj);
        int res = 0;

        for(TreeNode* v : leaf) {
            stack<pair<TreeNode*, int>> s;
            s.push({v, 0}); 
            set<TreeNode*> visited;
            while(!s.empty()) {
                auto [w, dis] = s.top();
                s.pop();
                if(dis > distance) continue;
                if(visited.count(w) == 0) {
                    visited.insert(w);
                    if(leaf.count(w) != 0 && v != w && dis <= distance) {
                        res++;
                    }
                    for(TreeNode* j : adj[w]) {
                        if(visited.count(j) == 0) {
                            s.push({j, dis+1});
                        }
                    }
                }
            }

        }
        return res/2;
    }
};