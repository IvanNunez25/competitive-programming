class Solution {
public:
    bool isHappy(int n) {
        
        if ( n == 1 )
            return true;
        
        int sum = 0;
        string num = to_string(n);
        set < int > res; 

        while ( num.length() >= 1 && res.find(n) == res.end() ) {

            res.insert( n );

            for ( int i = 0; i < num.length(); i++ )
                sum += pow( num[i] - '0', 2 );

            n = sum;
            num = to_string(n);
            sum = 0;

            if ( n == 1 )
                return true;
            
        }

        return false;
    }
};