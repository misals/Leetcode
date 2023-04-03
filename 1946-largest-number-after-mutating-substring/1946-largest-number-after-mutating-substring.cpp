class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {

        int n = num.size();
        
        for(int i = 0; i < n; i++) {
            char ch = (change[num[i] - '0']) + '0';
            if(num[i] < ch) {
                while(i < n && num[i] <= ch) {
                    num[i] = ch;
                    i++;
                    if(i < n) {
                        ch = (change[num[i] - '0']) + '0';
                    }
                }
                break;
            }
        }
        return num;
        
    }
};