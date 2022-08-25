class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        int n = ransomNote.size();
        int m = magazine.size();
        
        for(int i = 0; i < n; i++) {
            arr[ransomNote[i] - 'a']++;
        }
        for(int i = 0; i < m; i++) {
            if(arr[magazine[i] - 'a'] > 0) {
                arr[magazine[i] - 'a']--;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] > 0) {
                return false;
            }
        }
        return true;
    }
};