class Solution {
public:
    static bool canSortArray( vector<int> &nums) {
        int  n = nums.size();
        int pmax = 0, cmin = 0, cmax = 0;
        auto pcnt = 0;
        for (int v : nums) {
            if (auto ccnt = __builtin_popcount(v); pcnt == ccnt) {
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = v;
                pcnt = ccnt;
            }
        }
        return cmin >= pmax;
    }
};