class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> vis;
        
        q.push(start);
        vis.insert(start);
        
        int cnt = 0;
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                string node = q.front();
                q.pop();
                if(node == end) {
                    return cnt;
                }
                
                for(auto ch : "ACGT") {
                    for(int j = 0; j < 8; j++) {
                        string adjNode = node;
                        adjNode[j] = ch;
                        
                        if(!vis.count(adjNode) && find(bank.begin(),bank.end(),adjNode) != bank.end()) {
                            vis.insert(adjNode);
                            q.push(adjNode);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};