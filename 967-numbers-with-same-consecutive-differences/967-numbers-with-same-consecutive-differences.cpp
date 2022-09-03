class Solution {
public:
    int countDigit(int num) {
        int cnt = 0;
        while(num > 0) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    
    void findNumbers(int num, int n, int k, vector<int> &ans) {
        if(countDigit(num) == n) {
            ans.push_back(num);
            return;
        }
        for(int i = 0; i <= 9; i++) {
            int lastDigit = num % 10;
            if(abs(lastDigit - i) == k) {
                findNumbers(num * 10 + i, n, k, ans);
            }
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        for(int i = 1; i <= 9; i++) {
            findNumbers(i, n, k, ans);
        }
        
        return ans;
    }
};