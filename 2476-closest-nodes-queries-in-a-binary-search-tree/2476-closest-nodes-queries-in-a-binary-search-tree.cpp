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
    void inOrder(TreeNode* root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        inOrder(root -> left, v);
        v.push_back(root -> val);
        inOrder(root -> right, v);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inOrder(root, v);
        
        int sz = v.size();
        int n = queries.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            int val1 = queries[i];
            vector<int> temp(2, -1);
            int low = 0;
            int high = sz - 1;
            
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(v[mid] == val1) {
                    temp[0] = val1;
                    temp[1] = val1;
                    break;
                }
                else if(v[mid] > val1) {
                    temp[1] = v[mid];
                    high = mid - 1;
                }
                else {
                    temp[0] = v[mid];
                    low = mid + 1;
                }
            }
            ans.push_back(temp);
            
        }
        return ans;
        
    }
};