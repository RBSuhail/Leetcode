class Solution {
public:
    bool solve(const string& s, const string& p) {
        if (p.empty()) return s.empty();
        bool isMatchFirstChar = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.size() > 1 && p[1] == '*') {
        return solve(s, p.substr(2))||(isMatchFirstChar && solve(s.substr(1), p));
        }return isMatchFirstChar && solve(s.substr(1), p.substr(1));
    }
    bool isMatch(const string& s, const string& p) { return solve(s, p); }
};
