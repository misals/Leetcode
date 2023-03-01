class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &num:nums) minHeap.push(num);
        nums.clear();
        while (!minHeap.empty()) {
            nums.emplace_back(minHeap.top());
            minHeap.pop();
        }
        return nums;
    }
};