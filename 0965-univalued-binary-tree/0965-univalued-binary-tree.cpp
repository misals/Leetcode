/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int &prev, bool &flag) {
        if(root == NULL) {
            return;
        }
        solve(root -> left, prev, flag);
        if(prev != -1) {
            if(root -> val != prev) {
                flag = false;
            }
        }
        prev = root -> val;
        solve(root -> right, prev, flag);
    }
    
    bool isUnivalTree(TreeNode* root) {
        int prev = -1;
        bool flag = true;
        solve(root, prev, flag);
        
        return flag;
    }
};