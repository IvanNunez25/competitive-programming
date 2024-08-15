class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, int> left, right;
        vector<int> results;
        long m = 1, n = 1;
        
        left[0] = 1;
        right[nums.size() - 1] = 1;
        
        for ( int i = 1; i < nums.size(); i++ ) {
            
            m *= nums[i-1];
            n *= nums[ nums.size() - i ];
            
            left[i] = m;
            right[ nums.size() - 1 - i ] = n;
            
        }
        
        for ( int i = 0; i < nums.size(); i++ )
            results.push_back( left[i] * right[i] );
                
        
        return results;
    }
};