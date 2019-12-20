class Solution {
public:
    bool isValid(string S) {
        vector<char> vstack;
        
        for(int i= 0; i< S.length(); ++i){
            int n= vstack.size();
            if(S[i] != 'c'){
                vstack.push_back(S[i]);
            } else {
                if( n >= 2 && vstack[n-1] == 'b' && vstack[n-2] == 'a'){
                    vstack.pop_back();
                    vstack.pop_back();
                }
            }
        }
        
        return vstack.empty();
    }
};