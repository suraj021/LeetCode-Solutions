class Solution {
public:
    int nextGreaterElement(long n) {
        string s= to_string(n);
        
        next_permutation(s.begin(), s.end());
        
        auto num= stoll(s);
        
        return num > INT_MAX || num <= n ? -1 : num;
    }
};