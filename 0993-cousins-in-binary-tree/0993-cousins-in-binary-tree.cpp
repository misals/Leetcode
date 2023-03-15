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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        map<TreeNode*, TreeNode*> mp;
        
        while(!q.empty()) {
            int n = q.size();
            
            int cnt = 0;
            
            TreeNode* par1;
            TreeNode* par2;
            
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                if(node -> val == x || node -> val == y) {
                    cnt++;
                    if(cnt == 1) {
                        par1 = mp[node];
                    }
                    else if(cnt == 2) {
                        par2 = mp[node];
                    }
                }
                if(node -> left != NULL) {
                    mp[node -> left] = node;
                    q.push(node -> left);
                }
                if(node -> right != NULL) {
                    mp[node -> right] = node;
                    q.push(node -> right);
                }
            }
            if(cnt == 2) {
                if(par1 != par2) {
                    return true;
                }
            }
        }
        return false;
    }
};