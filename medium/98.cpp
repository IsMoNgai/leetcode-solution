#include <iostream>
#include <vector>

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
    void bst(TreeNode* root, vector<int> &check) {
        if(root->left) {
            bst(root->left, check);
        }
        check.push_back(root->val);
        if(root->right) {
            bst(root->right, check); 
        }
    } 
    bool isValidBST(TreeNode* root) {
        vector<int> check;
        bst(root, check);
        bool isValid = true;
        for(int i = 0; i < check.size()-1; i++) {
            if(check[i+1] <= check[i]) isValid = false;
        }
        return isValid;
    }
};