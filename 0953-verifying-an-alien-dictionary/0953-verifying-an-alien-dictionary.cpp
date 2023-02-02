class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26] = {0};
        int n = order.size();
        
        for(int i = 0; i < n; i++) {
            arr[order[i] - 'a'] = i;
        }
        
        int sz = words.size();
        for(int i = 0; i < sz - 1; i++) {
            string str1 = words[i];
            string str2 = words[i + 1];
            
            int len = min(str1.size(), str2.size());
            bool flag = false;
            
            for(int j = 0; j < len; j++) {
                if(arr[str1[j] - 'a'] > arr[str2[j] - 'a']) {
                    return false;
                }
                if(arr[str1[j] - 'a'] < arr[str2[j] - 'a']) {
                    flag = true;
                    break;
                }
            }
            
            if(str1.size() > str2.size() && !flag) {
                return false;
            }
        }
        return true;
    }
};