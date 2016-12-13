class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= (int)nums.size();
        vector< vector<int> > ans;
        
        sort( nums.begin(), nums.end() );
        
        for( int i= 0; i< n; ++i ){
            
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) 
                break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) 
                continue;
        
            for( int j= i+1; j< n; ++j ){
                
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) 
                    break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) 
                    continue;
                
                int start= j+1;
                int end= n-1;
                int fin= target - nums[i] - nums[j];
                vector<int> v( 4, 0 );
                
                //cout << i << ' ' << j << ' ' << fin << endl;
                
                while( start < end ){
                    int x= nums[start];
                    int y= nums[end];
                    
                    //cout << '\t' << start << ' ' << end << ' ' << x+y << ' ';
                    
                    if( x+y < fin ){
                        start++;
                    }else if( x+y > fin ){
                        end--;
                    }else{
                        
                        v[0]= nums[i];
                        v[1]= nums[j];
                        v[2]= nums[start];
                        v[3]= nums[end];
                        
                        ans.push_back( v );
                        
                        while( start < end && nums[start]== x )
                            start++;
                        while( start < end && nums[end]== y )
                            end--;
                        
                    }
                    
                  //  cout << start << ' ' << endl;
                    
                }
                
                while( j < n && nums[j]== nums[j+1] )
                    j++;
                    
                //cout << endl;
            }
            
            while( i < n && nums[i]== nums[i+1] )
                i++;
        }
        
        return ans;
    }
};