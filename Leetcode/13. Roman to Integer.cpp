class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map < char, int > roman = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int current = 0, past = 0, i = s.length() - 1, decimal = 0;
        
        do {
            
            if ( i != s.length() - 1 )
                past = current;
            
            current = roman[ s[i] ];
            
            if ( past != 0 && current < past )
                decimal -= current;
            else
                decimal += current;
            
            i--;
            
        } while ( i >= 0 );
        
        return decimal;

    }
};