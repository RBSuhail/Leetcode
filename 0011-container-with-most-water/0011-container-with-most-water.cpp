class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int A2, w, h;
        int i = 0, j = n - 1;
        int A1 = 0;
        while (j > i) {
            h = min(height[i], height[j]);
            w = j - i;
            A1 = max(A1, h * w);
            //    After that, we want to move one of the pointers. How can we
            //    judge it? It's simple. We want to keep taller height between
            //    left and right because there is a possibility that we will get
            //    max area with the taller height.
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return A1;
    }
};