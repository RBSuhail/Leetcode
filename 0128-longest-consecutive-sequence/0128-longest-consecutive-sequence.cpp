class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int it : nums) {
            if (st.find(it - 1) == st.end()) {
                int currentNum = it;
                int cnt = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum += 1;
                    cnt += 1;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
