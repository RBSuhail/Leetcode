class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>cnt(24,0);
        for(int i=0;i<24;i++)
        {
            for(auto it:candidates)
            {
                if(it&1<<i)
                cnt[i]++;
            }
        }
        int ans=*max_element(begin(cnt),end(cnt));
        return ans;
    }
};