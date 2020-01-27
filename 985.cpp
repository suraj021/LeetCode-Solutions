class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum= 0;
        
        for(int x: A){
            if(x%2== 0) sum+= x;
        }
        
        for(int i= 0; i< queries.size(); ++i){
            int val= queries[i][0];
            int id= queries[i][1];
            
            if(A[id]%2 == 0)
                sum-= A[id];

            A[id]+= val;
            
            if(A[id]%2 == 0)
                sum+= A[id];
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};