class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int sz = arr.size();
        
        if(sz == 1 && arr[0] == 0) return true;
        
        for(int i = 0; i < sz; i++) {
            if(arr[i] == 0) {
                if(i == 0 && i + 1 < sz && arr[i+1] == 0) {
                    n--;
                    arr[i] = 1;
                }
                else if(i - 1 >= 0 && arr[i-1] == 0 && i + 1 < sz && arr[i+1] == 0) {
                    arr[i] = 1;
                    n--;
                    
                }
                else if(i == sz - 1 && i - 1 >= 0 && arr[i-1] == 0) {
                    n--;
                    arr[i] = 1;
                }
            }
        }
        
        if(n <= 0) return true;
        
        return false;
    }
};