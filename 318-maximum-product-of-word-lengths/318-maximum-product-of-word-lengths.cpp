class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> v(n, 0);
        vector<int> word_len(n, 0);
        for(int i = 0; i < n; i++) {
            string w = words[i];
            int len = w.size();
            int num = 0;
            for(int j = 0; j < len; j++) {
                num |= 1 << (w[j] - 'a');
            }
            v[i] = num;
            word_len[i] = len;
        }
        int maxProduct = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if((v[i] & v[j]) == 0) {
                    maxProduct = max(maxProduct, word_len[i] * word_len[j]);
                }
            }
        }
        return maxProduct;
    }
};