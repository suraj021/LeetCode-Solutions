class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= (int)nums.size();
        
        if( n<= 1 )
            return n;
        
        int i= 0;
        
        for( int j= 1; j< n; ++j ){
            if( nums[j]!= nums[i] ){
                i++;
                nums[i]= nums[j];
            }
        }
        
        return i+1;
    }
};