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
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, -1}});
        
        int ans = 0;
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                ans = max(ans, node.second.first);
                
                if(node.first -> left != NULL) {
                    if(node.second.second != 0) {
                        q.push({node.first -> left, {node.second.first + 1, 0}});
                    }
                    else {
                        q.push({node.first -> left, {1, 0}});
                    }   
                }
                
                if(node.first -> right != NULL) {
                    if(node.second.second != 1) {
                        q.push({node.first -> right, {node.second.first + 1, 1}});
                    }
                    else {
                        q.push({node.first -> right, {1, 1}});
                    }   
                }
            }
        }
        return ans;
    }
};