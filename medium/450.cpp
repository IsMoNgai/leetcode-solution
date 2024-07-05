#include <iostream>

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
    // min replace node from left subtree if two trees exist
    int replaceNode(TreeNode* root) {
        if(root->right) {
            return replaceNode(root->right);
        } else {
            int val = root->val;
            root = nullptr;
            return val;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(root->left && root->right) {
                int replace = replaceNode(root->left);
                root->val = replace;
                root->left = deleteNode(root->left, replace);
            }
            else if(root->left) {
                return root->left;
            } 
            else if(root->right) {
                return root->right;
            }
            else {
                return nullptr;
            }
        }
        return root;
    }
};