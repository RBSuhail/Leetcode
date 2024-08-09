class Solution {
public:
int t[200][200];
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i==0||j==0)t[i][j]=1;
                else t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }
        return t[m - 1][n - 1];
    }
};