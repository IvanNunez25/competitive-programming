class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map < int , int > frequencies;
        vector < int > results;

        sort( nums.begin(), nums.end() );

        for( int i : nums )
            frequencies[i]++;
        
        vector< pair< int, int > > elements( frequencies.begin(), frequencies.end() );

        sort( elements.begin(), elements.end(), []( const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        for ( auto& pair : elements )
            for ( int i = 0; i < pair.second; i++ )
                results.push_back( pair.first ); 
        
        return results;
        
    }
};