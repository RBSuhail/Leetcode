class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0, j = 0, n = nums.size();
        long long count = 0, sum = 0, total = 0;

        for (; j < n; j++) {
            sum += nums[j];
            count++;

        
            for (;sum * count >= k && i <= j;i++) {
                sum -= nums[i];
                count--;
            }

            // Add the number of valid subarrays ending at j
            total += count;
        }

        return total;
    }
};
