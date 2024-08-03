class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSumIndex;
        int maxLength = 0;
        int prefixSum = 0;

        prefixSumIndex[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 1) ? 1 : -1;

            if (prefixSumIndex.count(prefixSum)) {
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            } else {
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};