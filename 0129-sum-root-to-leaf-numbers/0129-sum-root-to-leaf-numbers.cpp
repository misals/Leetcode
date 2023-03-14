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
    int ans = 0;
    void solve(TreeNode* root, int &sum) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            sum = sum * 10 + root -> val;
            cout << sum << " ";
            ans += sum;
            sum /= 10;
            return;
        }
        sum = sum * 10 + root -> val;
        solve(root -> left, sum);
        solve(root -> right, sum);
        sum /= 10;
        
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        
        solve(root, sum);
        
        return ans;
    }
};