class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int closest = nums[0];
        for ( int n : nums ) {
            if ( n == 0 )
                return 0;
            if ( n > 0 && n <= abs(closest) )
                return n;
            if ( n < 0 && n > closest )
                closest = n;
        }

        return closest;
    }
};