class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n; i++) {
            int j = i;
            bool flag = false;
            while(j + 1 < n && nums[j] == nums[j+1]) {
                j++;
                flag = true;
            }
            if(flag == true) {
                nums[k] = nums[i];
                k++;
                nums[k] = nums[j];
                k++;
                i = j;
            } else {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};