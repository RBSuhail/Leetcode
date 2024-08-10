class Solution {
public:
    int atLeastKIntegers(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0, total = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (; j < n; j++) {
            mp[nums[j]]++;
            for(;mp.size() >= k;i++) {
                total += n - j;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
            }
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total = atLeastKIntegers(nums, k) - atLeastKIntegers(nums, k + 1);
        return total;
    }
};
