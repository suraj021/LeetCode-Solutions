class Solution {
public:
    int numDecodings(string s) {   
        if(s[0]== '0') return 0;
        int n= (int)s.length();
        int dp[n]= {0};
        
        dp[0]= 1;
        
        for(int i= 1; i< n; ++i){
            int x= (s[i]-'0');
            int y= (s[i-1]-'0')*10 + x;
            
            if(x > 0 && x < 10){
                dp[i]+= dp[i-1];
            }
            if(y>= 10 && y<= 26){
                dp[i]+= i >= 2 ? dp[i-2] : 1;
            }
        }
        return dp[n-1];
    }
    
    // https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
};