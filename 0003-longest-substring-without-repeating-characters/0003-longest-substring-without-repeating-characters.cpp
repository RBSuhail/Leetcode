class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0,j=0,len=0;
        for(;j<n;j++)
        {   mp[s[j]]++;
            for(;mp[s[j]]>1;i++)
            {
                mp[s[i]]--;
            }
            len=max(len,j-i+1);
        }return len;
    }
};