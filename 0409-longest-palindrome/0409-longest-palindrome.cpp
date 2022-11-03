class Solution {
public:
    int longestPalindrome(string s) {
        int arr1[26] = {0};
        int arr2[26] = {0};
        int n = s.size();
        bool flag = true;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                arr1[s[i] - 'a']++;
            }
            else {
                arr2[s[i] - 'A']++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(arr1[i] % 2 == 0) {
                ans += arr1[i];
            }
            else if(flag) {
                ans += arr1[i];
                flag = false;
            }
            else {
                arr1[i]--;
                ans += arr1[i];
            }
            
            if(arr2[i] % 2 == 0) {
                ans += arr2[i];
            }
            else if(flag) {
                ans += arr2[i];
                flag = false;
            }
            else {
                arr2[i]--;
                ans += arr2[i];
            }
        }
        return ans;
    }
};