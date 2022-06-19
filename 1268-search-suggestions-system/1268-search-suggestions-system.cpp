class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<string> temp;
        sort(products.begin(), products.end());
        int n= searchWord.size();
        string curr = "";
        
        for(int i = 0; i < n; i++) {
            curr += searchWord[i];
            temp.clear();
            for(int i = 0; i < products.size(); i++) {
                if(products[i].substr(0, curr.size()) == curr) {
                    temp.push_back(products[i]);
                }
                if(temp.size() == 3) {
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};