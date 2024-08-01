/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void path ( TreeNode* node, int& sum, int& target, vector < vector < int > > & results, vector < int > & option ) {

        if ( node == nullptr )
            return;

        sum += node->val;
        option.push_back( node->val );

        if ( sum == target && node->left == nullptr && node->right == nullptr ) {
            results.push_back( option );
        } else {

            if ( node -> left != nullptr )
                path( node->left, sum, target, results, option);

            if ( node -> right != nullptr )
                path( node->right, sum, target, results, option);

        }

        sum -= node->val;
        option.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector < vector < int > > results;
        vector < int > option;
        int sum = 0;
        path( root, sum, targetSum, results, option);
        return results;
    }
};