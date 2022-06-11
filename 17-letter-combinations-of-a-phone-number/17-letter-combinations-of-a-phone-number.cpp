class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        int n = digits.size();
        queue<pair<int, string>> q;
        q.push({0, ""});
        vector<string> ans;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it.first;
            string s = it.second;
            
            for(char c : mp[digits[i]]) {
                string str = s;
                str += c;
                if(i == n - 1) {
                    ans.push_back(str);
                } else {
                    q.push({i+1, str});
                }
            }
        }
        return ans;
    }
};