class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n= S.length();
        int i, j;
        i= 0; j= n-1;
        
        while(i < j){
            if(!isalpha(S[i])){
                i++;
            } else if(!isalpha(S[j])){
                j--;
            } else {
                swap(S[i], S[j]);
                i++; j--;
            }
        }
        
        return S;
    }
};