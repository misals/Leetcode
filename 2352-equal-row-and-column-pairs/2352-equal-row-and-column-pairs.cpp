class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> pq;  // Map to count occurrences of each row
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            pq[grid[i]]++;  // Count occurrences of each row
        }
        
        map<vector<int>,int> col;  // Map to count occurrences of each column
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(grid[j][i]);  // Extracting column values and storing them in a vector
            }
            
            col[temp]++;  // Count occurrences of each column
        }
        
        int count=0;
        for(auto &i:pq)
        {
            if(col.find(i.first)!=col.end())  // Check if the column exists in the map
            {
                count += (i.second)* col[i.first];  // Calculate the count of equal pairs
            }
        }
        return count;  // Return the count of equal pairs
        
    }
};