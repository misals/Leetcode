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
    int maxLevelSum(TreeNode* root) {
        int cnt = 1;
        int maxi = INT_MIN;
        int ans = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                sum += node -> val;
                
                if(node -> left != NULL) {
                    q.push(node -> left);
                }
                if(node -> right != NULL) {
                    q.push(node -> right);
                }
            }
            if(sum > maxi) {
                maxi = sum;
                ans = cnt;
            }
            cnt++;
        }
        return ans;
    }
};