class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            
            int first = -1;
            int last = -1;
            for(int j = 0; j < n; j++) {
                if(s[i] == s[j] && first == -1) {
                    first = j;
                }
                else if(s[i] == s[j]) {
                    last = j;
                    break;
                }
             }
            
            int ind = s[i] - 'a';
            if(distance[ind] != last - first - 1) {
                return false;
            }
        }
        return true;
    }
};