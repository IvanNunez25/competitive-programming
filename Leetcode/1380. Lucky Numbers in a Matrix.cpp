#include <bits/stdc++.h>

using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {

    set < int > maximum, minimum;

    for( vector < int > v : matrix ) {
        sort( v.begin(), v.end() );
        minimum.insert( v[0] );
    }
    
    for ( int k = 0; k < matrix[0].size(); k++ ) {
        
        sort(matrix.begin(), matrix.end(), [k](const vector<int>& a, const vector<int>& b) {
                return a[k] > b[k]; });
                
        maximum.insert( matrix[0][ k ] );
    }
    
    vector<int> intersection;

    set_intersection(minimum.begin(), minimum.end(), maximum.begin(), maximum.end(), back_inserter(intersection));

    return intersection;
    
}

int main()
{
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,17,16}};
    vector < int > lucky =  luckyNumbers( matrix );
    
    for( int i : lucky )
        cout << i << endl;

    return 0;
}