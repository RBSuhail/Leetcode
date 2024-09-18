class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto lambda=[](int a,int b)
        {
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        };
        sort(nums.begin(),nums.end(),lambda);
        string s="";
        if(nums[0]==0)return "0";
        for(auto it:nums)
        {
            s+=to_string(it);
        }return s;
    }
};