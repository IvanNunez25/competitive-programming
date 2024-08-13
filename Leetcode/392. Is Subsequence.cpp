class Solution {
public:
    bool isSubsequence(string s, string t) {

        int T = t.length(), S = s.length(), i = 0, j = 0;
        while ( i < T && j < S ) {
            if ( t[i] == s[j] )
                j++;
            i++;
        }

        return j == S;
        
    }
};