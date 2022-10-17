class Solution {
public:
    bool checkIfPangram(string s) {
        int arr[26] = {0};
        int n = s.size();
        for(int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] == 0) {
                return false;
            }
        }
        return true;
    }
};