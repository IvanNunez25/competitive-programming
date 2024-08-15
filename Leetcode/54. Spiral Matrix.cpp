class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector < int > output;
        long n = matrix.size() * matrix[0].size(), renDown = matrix.size(), colRight = matrix[0].size(), renUp = 0, colLeft = 0;
        int i = 0, j = 0;
        bool right = true, up = false, horizontal = true;
        
        while ( output.size() < n ) {
            
            if ( horizontal ) {
                
                if ( right ) {
                    
                    if ( j >= colRight ){
                        j--;
                        i++;
                        colRight--;
                        right = false;
                        horizontal = false;
                    } else {
                        output.push_back( matrix[i][j] );
                        j++;
                    }
                    
                } else {
                    
                    if ( j < colLeft ) {
                        j++;
                        i--;
                        colLeft++;
                        right = true;
                        horizontal = false;
                    } else {
                        output.push_back( matrix[i][j] );
                        j--;
                    }
                }
                
            } else {
                
                if ( up ) {
                    
                    if ( i <= renUp ) {
                        i++;
                        j++;
                        renUp++;
                        up = false;
                        horizontal = true;
                    } else {
                        output.push_back( matrix[i][j] );
                        i--;
                    }
                } else {
                    
                    if ( i >= renDown ){
                        i--;
                        j--;
                        renDown--;
                        up = true;
                        horizontal = true;
                    } else {
                        output.push_back( matrix[i][j] );
                        i++;
                    }
                }
                
            }
        }
        
        return output;
    }
};