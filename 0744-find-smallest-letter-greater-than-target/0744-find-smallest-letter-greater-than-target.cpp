class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ch = letters[0];
        
        for(int i = 0; i < n; i++) {
            if(letters[i] > target) {
                ch = letters[i];
                break;
            }
        }
        return ch;
    }
};