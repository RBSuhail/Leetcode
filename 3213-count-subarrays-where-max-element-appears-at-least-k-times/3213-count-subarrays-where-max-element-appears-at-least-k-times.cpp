class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,count=0,n=nums.size(),maxEle=INT_MIN;
        for(auto it:nums)maxEle=max(maxEle,it);
        long long total=0;
        for(;j<n;j++)
        {
            if(nums[j]==maxEle)
            count++;
            for(;count==k;i++)
            {
                total+=n-j;
                if(nums[i]==maxEle)
                count--;
            }
        }return total;
    }
};