class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        if ( nums.size() == 0 )
            return {};
        
        if ( nums.size() == 1 )
            return {to_string(nums[0])};

        long a = nums[0], b = nums[0], count = 0, initialA = nums[0];
        vector < string > ranges;
        string range = "";

        for ( int i = 1; i < nums.size(); i++) {
            b = nums[i];
            
            if ( b != a + 1 ) {
                if ( count > 0 ) {
                    range = to_string(initialA) + "->" + to_string(a);
                } else {
                    range = to_string(initialA);
                }
                initialA = b;
                count = 0;
                ranges.push_back( range );
                range = "";
            } else {
                count++;
            }

            a = b;
        }
        
        if ( b != a + 1 ) {
            if ( count > 0 ) {
                range = to_string(initialA) + "->" + to_string(a);
            } else {
                range = to_string(initialA);
            }
            initialA = b;
            count = 0;
            ranges.push_back( range );
            range = "";
        } else {
            count++;
        }
        
        return ranges;
    }
};