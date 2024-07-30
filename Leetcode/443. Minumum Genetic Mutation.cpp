class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        set < string > geneBank( bank.begin(), bank.end() );
        if ( geneBank.find( endGene ) == geneBank.end() )
            return -1;
        
        queue < pair < string, int > > line;
        set < string > visited;
        
        line.push( { startGene, 0 } );
        visited.insert( startGene );
        
        vector < char > genes = {'A', 'C', 'G', 'T'};
        
        while ( !line.empty() ) {
            auto [current, steps] = line.front();
            line.pop();
            
            if (current == endGene) 
                return steps;
            
            for ( int i = 0; i < current.length(); i++) {
                char original = current[i];
                for ( char gene : genes ) {
                    if ( gene != original ) {
                        current[i] = gene;
                        if ( geneBank.find(current) != geneBank.end() && visited.find(current) == visited.end() ) {
                            line.push( { current, steps + 1 } );
                            visited.insert( current );
                        }
                    }
                }
                current[i] = original;
            }
        }
        
        return -1;
    }
};