// We only have to count the number of nodes with zero incoming edges.

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false); 
        cin.tie(0); 

        vector < int > reachable_nodes (n, 0);
        for( vector < int > v : edges )
            reachable_nodes[ v[1] ]++;
        
        vector < int > nodes;
        for ( int i = 0; i < n; i++ )
            if ( reachable_nodes[i] == 0 )
                nodes.push_back( i );
        
        return nodes;

    }
};