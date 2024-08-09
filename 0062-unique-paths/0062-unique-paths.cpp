#include <vector>
#include <cstring>

class Solution {
public:
    

    int uniquePaths(int m, int n) {
       int t[200][200]={-1};

        // Initialize the first row and first column
        for (int i = 0; i < m; ++i) {
            t[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            t[0][j] = 1;
        }

        // Fill the rest of the table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }

        return t[m - 1][n - 1];
    }
};
