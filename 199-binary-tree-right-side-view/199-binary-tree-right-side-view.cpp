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
    vector<int> ans;
    void help(TreeNode* root, int level) {
        if(root == NULL) return;
        
        if(level == ans.size()) {
            ans.push_back(root -> val);
        }
        help(root -> right, level + 1);
        help(root -> left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return ans;
        
        help(root, 0);
        
        return ans;
    }
};