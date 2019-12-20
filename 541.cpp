class Solution {
public:
    string reverseStr(string s, int k) {
        _reverseStr(s, 0, k, k);
        
        return s;
    }
    
    void _reverseStr(string& s, int start, int end, int k){
        if(start >= s.length()) return;
        string::iterator till = s.begin() + end > s.end() ? s.end() : s.begin() + end;
        reverse(s.begin() + start, till);
        
        _reverseStr(s, end + k, end + 2*k, k);
    }
};