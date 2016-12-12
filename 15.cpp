class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n= (int)nums.size();
        vector< vector< int > > ans;
        
        sort( nums.begin(), nums.end() );
        
        for( int i= 0; i< n; i++ ){
            int target= -nums[i];
            int start= i+1;
            int end= n-1;
            vector< int > tri( 3, 0 );
            
            while( start < end ){
                if( nums[start] + nums[end] < target )
                    start++;
                else if( nums[start] + nums[end] > target ){
                    end--;
                }else{
                    
                    tri[0]= nums[i];
                    tri[1]= nums[start];
                    tri[2]= nums[end];
                    
                    while( start < end &&  nums[start] == tri[1] )
                        start++;
                    while( start < end && nums[end]== tri[2] )
                        end--;
                        
                    ans.push_back( tri );
                }
            }
            
            while( i+1 < n && nums[i]== nums[i+1] )
                i++;
        }
        
        return ans;
        
    }
};