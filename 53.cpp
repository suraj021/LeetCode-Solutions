class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= (int)nums.size();
        int sum= 0, maxsum= 0;
        
        for( int i= 0; i< n; ++i ){
            sum+= nums[i];
            if( sum < 0 ){
                sum= 0;
            }else if( sum > maxsum ){
                maxsum= sum;
            }
        }
        
        if( maxsum== 0 ){
            maxsum= nums[0];
            
            for( int i= 1; i< n; ++i ){
                if( nums[i] > maxsum )
                    maxsum= nums[i];
            }
        }
        
        return maxsum;
    }
};