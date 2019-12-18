class Solution {
public:
    int findLUSlength(string a, string b) {
        int m= a.length();
        int n= b.length();
        return a == b ? -1 : max(m, n);
    }
};