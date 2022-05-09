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
        
        int n = digits.length();
        queue<pair<int, string>> q;
        q.push({0,""});
        vector<string> ans;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it.first;
            string str = it.second;
            
            for(auto c : mp[digits[i]]) {
                string s = str;
                s += c;
                if(i + 1 == n) {
                    ans.push_back(s);
                } else {
                    q.push({i+1, s});
                }
            }
        }
        return ans;
    }
};