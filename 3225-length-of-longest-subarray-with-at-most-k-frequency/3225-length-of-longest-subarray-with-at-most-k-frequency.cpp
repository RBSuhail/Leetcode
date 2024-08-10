class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0,count=0,n=nums.size();
        unordered_map<int,int>mp;
        for(;j<n;j++)
        {
            mp[nums[j]]++;
            for(;mp[nums[j]]>k;i++)
            {
                mp[nums[i]]--;
            }count=max(count,j-i+1);
        }return count;
    }
};