class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m= nums.size();
        int n= nums[0].size();
        
        if(m*n != r*c || m==r && n==c)  return nums;
        
        int x, y;
        vector<vector<int>> ans(r, vector<int>(c));

        x= y= 0;
        
        for(int i= 0; i< m; ++i){
            for(int j= 0; j< n; ++j){
                ans[x][y]= nums[i][j];
                y++;
                
                if(y >= c){
                    y= 0;
                    x++;
                }
            }
        }
        
        return ans;
    }
};