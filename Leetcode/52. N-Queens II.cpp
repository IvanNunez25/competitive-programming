class Solution {
public:

    bool checkQueens ( int x, int y, int n, vector < tuple < int, int > > & queens ) {
    
        if ( queens.empty() )
            return true;
            
        for ( tuple < int, int > t : queens ) {
            if ( x == get<0>(t) || y == get<1>(t) || ( abs ( x - get<0>(t) ) ==  abs ( y - get<1>(t) ) ) )
                return false;
        }
        
        return true;
        
    }

    void solve ( int& count, 
                int n, 
                vector < tuple < int, int > > & queens,
                int ind_i ) {
        
        if ( queens.size() == n ){
            count++;
            return;
        }
        
        for ( int j = 0; j < n; j++ ) {
            
            if ( checkQueens( ind_i, j, n, queens ) ) {
                
                queens.push_back( make_tuple( ind_i, j ) );
                solve( count, n, queens, ind_i + 1 );
                queens.pop_back();
            } 
        }
            
    }
    
    int totalNQueens(int n) {

        int count = 0;
        vector < tuple < int, int > > queens;
        
        solve ( count, n, queens, 0 );
        
        return count;
        
    }
};