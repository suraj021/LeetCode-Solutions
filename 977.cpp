class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        int n= A.size();
        int i= 0, j= n-1;
        
        while(i <= j){
            if(abs(A[i]) >= abs(A[j])){
                ans.push_back(A[i]*A[i]);
                i++;
            } else {
                ans.push_back(A[j]*A[j]);
                j--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};