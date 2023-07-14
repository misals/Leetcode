class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> DP;
        int length = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int before= 0;
            if (DP.find(arr[i] - difference) != DP.end())
                before = DP[arr[i] - difference];
            DP[arr[i]] = 1 + before;
            length = max(DP[arr[i]], length);
        }
        return length;
    }
};