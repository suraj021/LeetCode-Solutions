class Solution {
public:
    int nextGreaterElement(long n) {
        string s= to_string(n);
        
        next_permutation(s.begin(), s.end());
        
        auto num= stoll(s);
        
        return num > INT_MAX || num <= n ? -1 : num;
    }

    int _nextGreaterElement(long n) {
        string s= to_string(n);
        
        if(!nextPermutation(s)) return -1;
        
        auto num= stoll(s);
        
        return num > INT_MAX || num <= n ? -1 : num;
    }
    
    bool nextPermutation(string &s){
        int n= (int)s.length();
        int i; // max index for which s[i] > s[i-1]
        
        for(i= n-1; i> 0; --i){
            if(s[i] > s[i-1]) break;
        }
                
        if(i== 0)   return false;
        
        int num= s[i-1];
        int smallest= i;
        
        for(int j= i+1; j< n; ++j){
            if(num < s[j] && s[j] < s[smallest])
                smallest= j;
        }
            
        swap(s[i-1], s[smallest]);        
        sort(s.begin()+i, s.end());
        
        return true;
    }
};