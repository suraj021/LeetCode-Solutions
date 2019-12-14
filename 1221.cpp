class Solution {
public:
    int balancedStringSplit(string s) {
        int l, r;
        l= r= 0;
        int count= 0;
        
        for(int i= 0; i< s.length(); ++i){
            l+= s[i] == 'L' ? 1 : 0;
            r+= s[i] == 'R' ? 1 : 0;
            
            if(l == r)  count++;
        }
        
        return count;
    }
};