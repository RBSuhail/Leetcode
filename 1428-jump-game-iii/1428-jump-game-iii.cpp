class Solution {
public:
    bool solve_dfs(vector<int>& arr, int pos, int n) {
        if(pos < 0 || pos >= n || arr[pos] < 0)
            return false;
        if(arr[pos] == 0)
            return true;
        
        arr[pos] = -arr[pos]; //mark it as visited
        return solve_dfs(arr, pos+arr[pos], n) || solve_dfs(arr, pos-arr[pos], n);
    }
  
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        return solve_dfs(arr, start, n);
        
    }
};
