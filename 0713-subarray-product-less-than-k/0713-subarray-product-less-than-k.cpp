


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0,i=0,j=0,product=1,n=nums.size();
        if(k<=1)return 0;
        for(;j<n;j++)
        {
            product*=nums[j];
            for(;product>=k&&i<=j;i++)
            {
                product/=nums[i];
            }count+=(j-i+1);
        }return count;
    }
};