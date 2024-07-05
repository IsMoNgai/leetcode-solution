#include <iostream>
#include <vector>
#include <algorithm>

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
    void helper(TreeNode* root, int targetSum, vector<int> &res, vector<vector<int>> &ans) {
        if(!root) return;
        targetSum -= root->val;
        res.push_back(root->val);
        if(!root->left && !root->right) {
            if(targetSum == 0) {
                ans.push_back(res);
            }
        }
        vector<int> nr(res);
        helper(root->left, targetSum, nr, ans);
        helper(root->right, targetSum, res, ans);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> res;
        helper(root, targetSum, res, ans);
        return ans;
    }
};