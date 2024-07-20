#include <iostream>
#include <vector>
#include <set>

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
    TreeNode* deleteNode(TreeNode* root, set<int> del, vector<TreeNode*>& res) {
        // inOrder traversal to make sure that the bottom is being dealing first and then work upward.
        // this way we wont need to worry about del nodes in subbranch which already put in res.
        if(root == nullptr) return nullptr;
        if(root->left) {
            root->left = deleteNode(root->left, del, res);
        }
        if(root->right) {
            root->right = deleteNode(root->right, del, res);
        }
        // did a find to search deleteNode from set instead of vector
        // another wway is to use count() != 0
        if(del.find(root->val) != del.end()) {
            if(root->left) {
                res.push_back(root->left);
            }
            if(root->right) {
                res.push_back(root->right);
            }
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        TreeNode* head = root;
        vector<TreeNode*> res;
        set<int> del(to_delete.begin(), to_delete.end());
        head = deleteNode(head, del, res);
        // remember to update the head
        if(head) {
            res.push_back(head);
        }
        return res;
    }
};
