#include <bits/stdc++.h>

using namespace std;

void solve ( vector < vector < int > > & subsets, vector < int > & nums, vector < int > & subset, int ind ) {
    
    subsets.push_back( subset );
    
    for( int i = ind; i < nums.size(); i++ ) {
        subset.push_back( nums[i] );
        solve( subsets, nums, subset, i + 1 );
        subset.pop_back();
    }
    
}

vector<vector<int>> subsets(vector<int>& nums) {
    
    vector < vector < int > > subsets;
    vector < int > subset;
    
    solve( subsets, nums, subset, 0 );
    
    return subsets;
    
}

int main()
{
    vector < int > nums = {1, 2, 3};
    vector < vector < int > > solutions = subsets( nums );
    
    for ( vector < int > v : solutions ) {
        for ( int i : v )
            cout << i << " ";
        cout << endl;
    }

    return 0;
}