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
    int findMax(vector<int> &nums, int start, int end) {
        int maxi = INT_MIN;
        int ind = -1;
        for(int i = start; i <= end; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                ind = i;
            }
        }
        return ind;
    }
    
    TreeNode* construct(vector<int> &nums, int start, int end) {
        if(start > end) {
            return NULL;
        }
        if(start == end) {
            return new TreeNode(nums[start]);
        }
        
        int ind = findMax(nums, start, end);
        TreeNode* root = new TreeNode(nums[ind]);
        root -> left = construct(nums, start, ind - 1);
        root -> right = construct(nums, ind + 1, end);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        TreeNode* root = construct(nums, start, end);
        
        return root;
    }
};