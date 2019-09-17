class Solution {
public:
    bool divisorGame(int N) {
        bool ans[N+1];
        for(int i= 0; i<= N; ++i)    ans[i]= false;
        
        ans[0]= ans[1]= false;
        
        for(int i= 2; i<= N; ++i){
            for(int j= 1; j< i; ++j){
                if(i%j== 0 && !ans[i-j]){
                    ans[i]= true;
                    break;
                }
            }
        }
        
        return ans[N];
    }
};