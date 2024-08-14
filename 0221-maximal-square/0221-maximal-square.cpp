class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dp[n][m];
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            if(dp[i][0])maxlen=1;
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i]-'0';
            if(dp[0][i])maxlen=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    maxlen=max(maxlen,dp[i][j]);
                }else
                dp[i][j]=0;
            }
        }return maxlen*maxlen;
    }
};