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
    void solve(TreeNode* root, int &prev, int &ans) {
        if(root == NULL) {
            return;
        }
        solve(root -> left, prev, ans);
        if(prev != -1) {
            ans = min(ans, root -> val - prev); 
        }
        prev = root -> val;
        solve(root -> right, prev, ans);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        solve(root, prev, ans);
        
        return ans;
    }
};