class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0, j= 1;

        // i is for even and j is for odd
        while(i < A.size() && j < A.size()){
            if(A[i]%2 && A[j]%2== 0){
                swap(A[i], A[j]);
                i+= 2;
                j+= 2;
            } else if(A[i]%2== 0){
                i+= 2;
            } else if(A[j]%2){
                j+= 2;
            }
        }
        
        return A;
    }
};