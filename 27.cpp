class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int  n= (int)nums.size();
        int j;
        for( j= 0; j< n; ++j ){
            if( nums[j]== val ){
                int k= j+1;
                while( k < n && nums[k]== val ){
                    k++;
                }
                
                if( k== n )
                    break;
                swap( nums[j], nums[k] );
            }
        }
        return j;
    }
};