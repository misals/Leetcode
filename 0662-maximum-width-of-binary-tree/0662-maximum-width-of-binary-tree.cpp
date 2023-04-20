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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        long long ans = 0;
        
        while(!q.empty()) {
            int n = q.size();
            
            long long minId = q.front().second;
            long long first, last;
            
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                long long currId = node.second - minId;
                q.pop();
                
                if(i == 0) {
                    first = node.second;
                }
                if(i == n - 1) {
                    last = node.second;
                }
                
                if(node.first -> left != NULL) {
                    q.push({node.first -> left, currId * 2 + 1});
                }
                
                if(node.first -> right != NULL) {
                    q.push({node.first -> right, currId * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};