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
   void swap(vector<int> &arr,
		int i, int j)
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int>arr,
			int N)
{
int ans = 0;
vector<int>temp = arr;

// Hashmap which stores the
// indexes of the input array
map <int, int> h;

sort(temp.begin(), temp.end());
for (int i = 0; i < N; i++)
{
	h[arr[i]] = i;
}
for (int i = 0; i < N; i++)
{
	// This is checking whether
	// the current element is
	// at the right place or not
	if (arr[i] != temp[i])
	{
	ans++;
	int init = arr[i];

	// If not, swap this element
	// with the index of the
	// element which should come here
	swap(arr, i, h[temp[i]]);

	// Update the indexes in
	// the hashmap accordingly
	h[init] = h[temp[i]];
	h[temp[i]] = i;
	}
}
return ans;
}
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = 0;
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                temp.push_back(node -> val);
                
                if(node -> left) {
                    q.push(node -> left);
                }
                if(node -> right) {
                    q.push(node -> right);
                }
            }
            int val = minSwaps(temp, temp.size());
            ans += val;
        }
        return ans;
    }
};