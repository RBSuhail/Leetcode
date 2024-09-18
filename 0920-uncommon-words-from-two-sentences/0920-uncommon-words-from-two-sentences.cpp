class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        string token="";
        unordered_map<string,int>mp;
        vector<string>s;
        while(ss1>>token)
        mp[token]++;
        stringstream ss2(s2);
        token="";
        while(ss2>>token)
        mp[token]++;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                s.push_back(it.first);
            }
        }return s;
    }
};