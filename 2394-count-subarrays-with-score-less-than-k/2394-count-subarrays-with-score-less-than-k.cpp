class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0, j = 0, n = nums.size();
        long long count = 0, sum = 0, total = 0;

        for (; j < n; j++) {
            sum += nums[j];
            count++;

            // Adjust the window if the score is greater than or equal to k
            while (sum * count >= k && i <= j) {
                sum -= nums[i];
                count--;
                i++;
            }

            // Add the number of valid subarrays ending at j
            total += count;
        }

        return total;
    }
};
