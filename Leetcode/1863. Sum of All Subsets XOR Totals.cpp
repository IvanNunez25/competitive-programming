class Solution {
public:

    int solve ( vector < int > & nums, int ind, int current ) {
    
        if ( ind == nums.size() )
            return current;
        
        return solve( nums, ind + 1, current ) + solve( nums, ind + 1, current^nums[ ind ] ); 
        
    }

    int subsetXORSum(vector<int>& nums) {
        return solve( nums, 0, 0 );
    }
};


class Solution {
public:

    void solve ( vector < vector < int > > & subsets, vector < int > & nums, vector < int > & subset, int ind ) {
        
        subsets.push_back( subset );
        
        for( int i = ind; i < nums.size(); i++ ) {
            subset.push_back( nums[i] );
            solve( subsets, nums, subset, i + 1 );
            subset.pop_back();
        }
        
    }
    
    int subsetXORSum(vector<int>& nums) {
        vector < vector < int > > subsets;
        vector < int > subset;
        
        solve( subsets, nums, subset, 0 );
        
        int xor_total = 0, x_or = 0;
        
        for ( vector < int > v : subsets) {
            x_or = 0;
            for (int i : v)
                x_or ^= i;
                
            xor_total += x_or;
        }
        
        return xor_total;
    }
};