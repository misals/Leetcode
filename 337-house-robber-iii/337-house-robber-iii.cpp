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
    pair<int,int> dfs(TreeNode* root) {
        if(root == NULL) return {0,0};
        
        auto p1 = dfs(root -> left);
        auto p2 = dfs(root -> right);
        
        int num1, num2;
        num1 = root -> val + p1.second + p2.second;
        num2 = max(p1.first, p1.second) + max(p2.first, p2.second);
        
        return {num1, num2};
    }
    
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL)
            return root -> val;
        
        
        pair<int,int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};