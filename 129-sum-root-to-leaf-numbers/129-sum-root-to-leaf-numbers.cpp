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
    vector<int> v;
    
    void inorder(TreeNode* root, int sum) {
        if(root == NULL) {
            return ;
        }
        if(root -> left == NULL && root -> right == NULL) {
            sum = sum * 10 + root -> val;
            v.push_back(sum);
            sum /= 10;
            return;
        }
        sum = sum * 10 + root -> val;
        inorder(root -> left, sum);
        inorder(root -> right, sum);
        sum /= 10;
    }
    
    int sumNumbers(TreeNode* root) {
        inorder(root, 0);
        
        int ans = 0;
        for(auto it : v) {
            ans += it;
        }
        
        return ans;
    }
};