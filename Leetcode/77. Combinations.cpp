#include <bits/stdc++.h>

using namespace std;

void solve ( vector < vector < int > > & solutions, vector < int > combination, vector < int > & nums, int & k, int ind ) {
    
    if (combination.size() == k) {
        solutions.push_back(combination);
        return;
    }

    for (int i = ind; i < nums.size(); ++i) {
        combination.push_back(nums[i]);
        solve(solutions, combination, nums, k, i + 1);
        combination.pop_back();
    }
    
}

vector<vector<int>> combine(int n, int k) {
    
    vector < vector < int > > solutions;
    vector < int > combination;
    vector < int > nums ( n );
    
    iota( nums.begin(), nums.end(), 1 );
    
    solve( solutions, combination, nums, k, 0 );
    
    return solutions;
    
}

int main() {
    
    vector < vector < int > > solutions = combine(4, 2);
    
    for ( vector < int > v : solutions ) {
        for ( int i : v )
            cout << i << " ";
        cout << endl;
    }

    return 0;
}