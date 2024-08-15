class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        
        for( int i = 1; i < strs.size() && prefix != ""; i++ ) {
            if ( strs[i].length() < prefix.length() ) 
                prefix = prefix.substr( 0, strs[i].length() );
            
            while( prefix != strs[i].substr(0, prefix.size() ) ) {
                prefix = prefix.substr( 0, prefix.length() - 1 );
            }
        }
        
        return prefix;
    }
};