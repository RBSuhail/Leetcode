class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            set<vector < int>> st;

            sort(nums.begin(), nums.end());
            int n = nums.size();

            for (int i = 0; i < n - 2; ++i)
            {
                int target = -nums[i];
                int j = i + 1;
                int k = n - 1;

                while (j < k)
                {
                    int sum = nums[j] + nums[k];

                    if (sum == target)
                    {
                        st.insert({ nums[i],
                            nums[j],
                            nums[k] });
                        ++j;
                        --k;
                    }
                    else if (sum < target)
                    {
                        ++j;
                    }
                    else
                    {
                        --k;
                    }
                }
            }

            vector<vector < int>> ans(st.begin(), st.end());
            return ans;
        }
};