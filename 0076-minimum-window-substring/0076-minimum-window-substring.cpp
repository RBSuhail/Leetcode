class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;
        int required = t.size();  // Total number of characters to match
        int minLength = INT_MAX, startIdx = 0;
        int i = 0, j = 0;

        for (; j < s.size(); j++) {
            if (mp.count(s[j])) {
                if (mp[s[j]] > 0) {
                    required--;  // Decrease the required count only when a needed character is found
                }
                mp[s[j]]--;  // Decrease the frequency in the map
            }

           for(;required == 0;i++) {  // All characters are matched
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    startIdx = i;
                }

                if (mp.count(s[i])) {
                    mp[s[i]]++;  // Increase the frequency as the character is about to be removed from the window
                    if (mp[s[i]] > 0) {
                        required++;  // Increase the required count if a needed character is removed
                    }
                }

                  // Shrink the window from the left
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(startIdx, minLength);
    }
};
