class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 0 || n == 1) {
            return 0;
        }
        
        int start = 0;
        int end = n - 1;
        int ans = 0;
        
        while(start < end) {
            int num = min(height[start], height[end]);
            ans = max(ans, num*(end - start));
            
            if(height[start] <= height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return ans;
    }
};