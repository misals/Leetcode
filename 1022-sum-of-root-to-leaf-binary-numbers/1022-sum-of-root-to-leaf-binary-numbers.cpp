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
    
    int compute(vector<string> &ans) {
        int sum = 0;
        for (string x : ans)
            sum += stoi(x, 0, 2);
        
        return sum;
    }
    
    void solve(TreeNode* root, string temp, vector<string> &ans) {
        if(root == NULL) {
            return;
        }
        temp += root -> val == 1 ? "1" : "0";
        solve(root -> left, temp, ans);
        if(root -> left == NULL && root -> right == NULL) {
            ans.push_back(temp);
        }
        solve(root -> right, temp, ans);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<string> ans;
        string temp;
        
        solve(root, temp, ans);
        
        return compute(ans);
    }
};