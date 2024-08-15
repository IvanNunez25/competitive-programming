class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort( intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        } );
        
        set < vector < int > > set_results;
        int i = 0, start = intervals[0][0], end = intervals[0][1];
        
        for ( i = 1; i < intervals.size(); i++ ) {
            if ( intervals[i][0] <= end ) {
                end = intervals[i][1] > end ? intervals[i][1] : end ;
            } else {
                set_results.insert( { start, end } );
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        
        set_results.insert( { start, end } );
        vector < vector < int > > results ( set_results.begin(), set_results.end() );
        
        return results;
    }
};