class NumArray {
private:
    int *sum;
public:
    NumArray(vector<int> &nums) {
        int n= (int)nums.size();
        sum= new int[n+1];
        
        sum[0]= 0;
        for( int i= 0; i< n; ++i ){
            sum[i+1]= sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        int res= sum[j+1] - sum[i];
        return res;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);