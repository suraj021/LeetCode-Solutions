class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i, j;
        int n= A.size();
        i= 0; j= n-1;
        
        while(i < j){
            if(A[i]%2== 1 && A[j]%2== 0){
                swap(A[i], A[j]);
                i++; j--;
            }
            
            if(A[i]%2== 0)  i++;
            if(A[j]%2== 1)  j--;
        }
        
        return A;
    }
};