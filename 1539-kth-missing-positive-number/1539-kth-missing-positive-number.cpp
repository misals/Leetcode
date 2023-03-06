class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int temp[10010] = {0};
        for(auto it : arr) {
            temp[it] = 1;
        }
        for(int i = 1; i <= 10000; i++) {
            if(temp[i] == 0) {
                k--;
                if(k == 0) {
                    return i;
                }
            }
        }
        return 0;
    }
};