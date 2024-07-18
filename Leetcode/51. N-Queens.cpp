class Solution {
public:

    void addBoard ( vector < vector < string > > & board, int n, vector < tuple < int, int > > & queens ) {
        
        vector < string > solution = {};
        string row = "";
        
        for ( int i = 0; i < n; i++ ) {
            row += '.';
        }
        
        for ( tuple < int, int > t : queens ) {
            
            string rowQueen = row;
            rowQueen[ get<1>(t) ] = 'Q';
            solution.push_back( rowQueen );
            
        }
        
        board.push_back( solution );
        
    }

    bool checkQueens ( int x, int y, int n, vector < tuple < int, int > > & queens ) {
        
        if ( queens.empty() )
            return true;
            
        for ( tuple < int, int > t : queens ) {
            if ( x == get<0>(t) || y == get<1>(t) || ( abs ( x - get<0>(t) ) ==  abs ( y - get<1>(t) ) ) )
                return false;
        }
        
        return true;
        
    }

    void solve ( vector < vector < string > > & board, 
                int n, 
                vector < tuple < int, int > > & queens,
                int ind_i ) {
                    
        
        if ( queens.size() == n ){
            addBoard( board, n, queens );
            return;
        }
           
        for ( int j = 0; j < n; j++ ) {
            
            
            if ( checkQueens( ind_i, j, n, queens ) ) {
                
                queens.push_back( make_tuple( ind_i, j ) );
                solve( board, n, queens, ind_i + 1 );
                queens.pop_back();
            } 
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector < vector < string > > solution;
        vector < tuple < int, int > > queens;
    
        solve ( solution, n, queens, 1 );
        
        return solution;
    }
};