#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0, count = 0;
        prefixSumIndex[0] = 1; 
        for (int num : nums) {
            prefixSum += num;

            if (prefixSumIndex.count(prefixSum - k)) {
                count += prefixSumIndex[prefixSum - k];
            }

            prefixSumIndex[prefixSum]++;
        }

        return count;
    }
};
