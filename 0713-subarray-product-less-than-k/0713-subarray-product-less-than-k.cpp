class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long l=0,r=0,ans=0,n=nums.size();
       long prod=1;

    //    importent step put to remember
        // if(k<=1)return 0;
        for(;r<n;r++){
            prod*=nums[r];
            
            for(;prod>=k && l<=r;l++){
                prod/=nums[l];
                
            }ans+=(r-l+1);
        }return ans;
    }
};