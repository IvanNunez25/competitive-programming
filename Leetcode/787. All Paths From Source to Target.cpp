class Solution {
public:

    void solve ( vector< vector< int > >& output, vector< vector< int > >& graph, vector< int >& path, int node) {

        if ( node == graph.size()-1 ) {
            output.push_back( path );
            return;
        }

        for ( int i : graph[node] ) {
            path.push_back( i );
            solve( output, graph, path, i );
            path.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector < vector < int > > output;
        vector < int > path = {0};
        solve( output, graph, path, 0 );
        return output;
    }
};