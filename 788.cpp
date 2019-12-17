class Solution {
public:
    int rotatedDigits(int N) {
        int dp[N+1] = {0};
        int ans= 0;
        // dp[i]= 0; //invalid
        // dp[i]= 1; // rotates to same number
        // dp[i]= 2; // rotates to different number
        
        for(int i= 0; i<= N; ++i){
            if(i< 10){
                if(i == 0 || i == 1 || i == 8)  dp[i]= 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9 ){
                    dp[i]= 2;
                    ans++;
                }
            } else {
                int a= dp[i/10];
                int b= dp[i%10];
                
                if( a == 1 && b == 1 )  dp[i] = 1;
                else if( a >= 1 && b >= 1 ){
                    dp[i] = 2;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};