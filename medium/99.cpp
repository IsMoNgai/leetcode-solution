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
    void dfs(TreeNode* root, vector<int> &check) {
        if(root->left) {
            dfs(root->left, check);
        }
        check.push_back(root->val);
        if(root->right) {
            dfs(root->right, check);
        }
    }

    void swapNode(TreeNode* root, int target, int swap) {
        if(!root) return;
        if(root->val == swap) {
            root->val = target;
        }
        else if(root->val == target) {
            root->val = swap;
        }
        swapNode(root->left, target, swap);
        swapNode(root->right, target, swap);
    }

    void recoverTree(TreeNode* root) {
        // find out which two need to swap
        // compare the array with sorted array
        // make a func that swap number
        vector<int> check;
        dfs(root, check);
        vector<int> temp;
        temp = check;
        sort(check.begin(), check.end());
        int l,r;
        for(int i = 0 ; i < check.size(); i++) {
            if(check[i] != temp[i]) {
                l = check[i];
                r = temp[i];
            }
        }
        swapNode(root, l, r);
    }
    // 1 3 2 4
    // 1 2 3 4
};