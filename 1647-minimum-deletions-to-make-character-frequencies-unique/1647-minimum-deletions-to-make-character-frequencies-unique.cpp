class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        vector<int> vec;
        for(auto it : mp) {
            vec.push_back(it.second);
        }
        set<int> st;
        sort(vec.begin(), vec.end());
        int sz = vec.size();
        int ans = 0;
        
        for(int i = sz - 1; i >= 0; i--) {
            int num = vec[i];
            if(st.find(num) == st.end()) {
                st.insert(num);
                ans += num;
            }
            else {
                while(st.find(num) != st.end() && num > 0) {
                    num--;
                }
                st.insert(num);
                ans += num;
            }
        }
        return n - ans;
    }
};