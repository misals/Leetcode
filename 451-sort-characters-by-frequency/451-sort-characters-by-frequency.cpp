class Solution {
public:
    
    static bool cmp(pair<char, int>& a, pair<char, int>& b)
    {
        return a.second > b.second;
    }
    string sort1(map<char, int>& M) {
        vector<pair<char, int> > A;
        for (auto& it : M) {
            A.push_back(it);
        }
        sort(A.begin(), A.end(), cmp);
        string str;
        for (auto& it : A) {
            int num = it.second;
            while(num--) {
                str.push_back(it.first);
            }
        }
        return str;
    }
    
    string frequencySort(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        string ans = sort1(mp);
        return ans;
    }
};