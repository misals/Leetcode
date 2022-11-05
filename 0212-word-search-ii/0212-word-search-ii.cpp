class Solution {
public:
    class TrieNode{
        public:
            TrieNode *links[26];
            bool end = false;
    };
    class Trie{
        public:
            TrieNode *root;
            Trie(){
                root = new TrieNode();
            }
            void insert(string &s){
                TrieNode* curr = root;
                for(auto &ch : s){
                    if(curr->links[ch - 'a'] == NULL){
                        curr->links[ch - 'a'] = new TrieNode();
                    }
                    curr = curr->links[ch - 'a'];
                }
                curr->end = true;
            }
            bool isValid(vector<vector<char>>& board, int x, int y){
                int row = board.size(), col = board[0].size();
                if(x<0 || x>=row || y<0 || y>=col || board[x][y]=='*') return false;
                return true;
            }
            void dfs(vector<vector<char>>& board, int i, int j, string &str, TrieNode* root, vector<string>&ans){
                if(!isValid(board, i, j))return;
                if(board[i][j] == '.')return;
                int idx = board[i][j] - 'a';
                if(!root->links[idx])return;    // this char on board not present in trie hence useless
                char ch = board[i][j];
                board[i][j] = '.';
                str.push_back(ch);     //creating string as it matching 
                if(root->links[idx]->end){
                    ans.push_back(str);      // a complete word found on board 
                    root->links[idx]->end = false;  // removing that word from trie
                }
                dfs(board, i + 1, j, str, root->links[idx], ans);
                dfs(board, i, j + 1, str, root->links[idx], ans);
                dfs(board, i - 1, j, str, root->links[idx], ans);
                dfs(board, i, j - 1, str, root->links[idx], ans);
                board[i][j]= ch;          // backtrack
                str.pop_back();
            }
    };
   
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         vector<string> ans;
        Trie *t1 = new Trie();
        for(auto & w: words){
           t1->insert(w);
        }
        string str = "";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                t1->dfs(board, i, j, str, t1->root, ans);
            }
        }
        return ans;
    }
};