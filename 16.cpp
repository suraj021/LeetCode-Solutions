class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= (int)nums.size();
        int ans;
        sort( nums.begin(), nums.end() );
        int diff= INT_MAX;

        for( int i= 0; i< n; ++i ){
            int start= i+1;
            int end= n-1;

            //cout << i << ' ';

            while( start < end ){
                int x= nums[i];
                int y= nums[start];
                int z= nums[end];
                int sum= x+y+z;
                int d= abs( sum-target );

                //cout << '\t' << start << ' ' << end << endl;
                //cout << '\t' <<sum << ' ' << d << ' ' << diff << ' ' << ans << endl;

                if( d < diff ){
                        ans= sum;
                        diff= d;
                }

                if( sum > target ){
                    end--;
                }else if( sum < target ){
                    start++;
                }else{
                    break;
                }

                //while( start < end && nums[start+1]== y )
                  //  start++;
                //while( start < end && nums[end-1]== z )
                  //  end--;

                //cout << start << ' ' << end << endl;
            }

            while( i+1 < n && nums[i]== nums[i+1] )
                i++;
        }

        //cout << endl;

        return ans;

    }
};