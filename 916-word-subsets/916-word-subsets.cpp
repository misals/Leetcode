class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int n = words1.size();
        
        int arr[26] = {0};
        int sz = words2.size();
        for(int i = 0; i < sz; i++) {
            int temp[26] = {0};
            for(int j = 0; j < words2[i].size(); j++) {
                temp[words2[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                arr[j] = max(arr[j], temp[j]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            int arr2[26] = {0};
            for(int j = 0; j < words1[i].size(); j++) {
                arr2[words1[i][j] - 'a']++;
            }
            bool flag = true;
            for(int j = 0; j < 26; j++) {
                if(arr[j] > arr2[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};