class Solution {
public:
    void solve(int k,vector<int>&arr,int &ans,int index)
    {
        if(arr.size()==1)
        {
            ans= arr[0];
            return;
        }
        
           index=(index+k)%arr.size();
            arr.erase(arr.begin()+index);
            solve(k,arr,ans,index);
        
    }
    int findTheWinner(int n, int k) {
        int ans=-1;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        arr[i]=i+1;
        
        

        solve(k-1,arr,ans,0);
        return ans;
    }
};