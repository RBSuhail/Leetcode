class Solution {
public:
    int longestValidParentheses(string s) {
        int op = 0, cl = 0, len = 0, n = s.size(), len2 = 0;
        for (int i = 0; i < n; i++) {
            s[i] == '(' ? op++ : cl++;
            if (cl > op) op = cl = 0;
            else if (op == cl) len = max(len, cl * 2);
        }
       op = cl = 0;
        for (int i = n - 1; i >= 0; i--) {
            s[i] == ')' ? cl++ : op++;
            if (op > cl) op = cl = 0;
            else if (op == cl) len2 = max(len2, op * 2);
        }
        
        return max(len, len2);
    }
};
