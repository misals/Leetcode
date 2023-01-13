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
    int solve(TreeNode* root, int &cnt) {
        if(root == NULL) {
            return 0;
        }
        int left = solve(root -> left, cnt);
        int right = solve(root -> right, cnt);
        if(root -> left && root -> left -> val == root -> val) {
            left += 1;
        }
        else {
            left = 0;
        }
        if(root -> right && root -> right -> val == root -> val) {
            right += 1;
        }
        else {
            right = 0;
        }
        cnt = max(cnt, left + right);
        return max(left, right);
        
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};