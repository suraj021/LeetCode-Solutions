class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n= (int)nums.size();
        
        for( int i= 0; i< n; ++i )
            if( nums[i]== target )
                return true;
        return false;
    }
};