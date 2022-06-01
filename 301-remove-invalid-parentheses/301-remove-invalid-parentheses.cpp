class Solution {
public:
    
    void solve(string s, vector<string> &ans, int removal, unordered_map<string,bool> &mp) {
        if(mp[s]) {
            return ;
        } 
        mp[s] = true;
        
        if(removal == 0) {
            int curr_removal = findRemoval(s);
            if(curr_removal == 0) {
                ans.push_back(s);
            }
            return;
        }
        
        for(int i = 0; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            string join = left + right;
            solve(join, ans, removal - 1, mp);
        }
        return;
    }
    
    int findRemoval(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            } else if(s[i] == ')') {
                if(st.size() > 0 && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(')');
                }
            }
        }
        return st.size();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int min_removal = findRemoval(s);
        vector<string> ans;
        unordered_map<string,bool> mp;
        solve(s, ans, min_removal, mp);
        return ans;
    }
};