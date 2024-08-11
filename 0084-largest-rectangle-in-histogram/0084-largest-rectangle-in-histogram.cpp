class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(n);
        vector<int> ans(n);
       for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != n && arr[s.top()] >= curr)
            s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
         for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
              s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> next(n),prev(n);
        next = nextSmallerElement(heights, n);
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};