class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //we have take -1 for zero mano ham kahin pahunch gaye
        //wahan wahin sum hai means beech mein equal 0 and 1,s hain
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
