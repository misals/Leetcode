class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(), words.end());
        set<string> s2(words.begin(), words.end());
        
        for(auto part : s1) {
            for(int i = 1 ; i < part.size(); i++) {
                s2.erase(part.substr(i));
            }
        }
        int cnt = 0;
        for(auto it : s2) {
            cnt += it.size() + 1;
        }
        return cnt;
    }
};