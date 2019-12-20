class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A== "" || B== "") return -1;
        int ans= -1;
        string a= A;
        
        for(int i= 0; i< B.length()/a.length()+2; ++i){
            if(A.find(B) != string::npos){
                ans= i;
                break;
            }
            A+= a;
        }
        
        return ans == -1 ? ans : ans+1;
    }
};