#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
    /*
    each des:
    des[0] = parent
    if des[2] : parent->left = des[1]
    else : parent -> right = des[1]

    initially root* = null
    first parent encounter set root to parent
    if parent get put in des[1] position set root to des[0]

    #strat 2:
    make a map to contain all node and then find which one is root
    */
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> m;
        set<int> childs;
    
        for(auto des : descriptions) {
            childs.insert(des[1]);
            if(m.find(des[0]) == m.end()) {
                m[des[0]] = new TreeNode (des[0]);
            }
            if(m.find(des[1]) == m.end()) {
                m[des[1]] = new TreeNode (des[1]);
            } 
            if(des[2]) {
                m[des[0]]->left = m[des[1]];
            } else {
                m[des[0]]->right = m[des[1]];
            }
        }   

        for(auto des : descriptions) {
            if(childs.find(des[0]) == childs.end()) {
                return m[des[0]];
            }
        }

        return nullptr;
    }
};