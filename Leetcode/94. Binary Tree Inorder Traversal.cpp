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

    void solve ( TreeNode* node,  vector < int > & output ) {

        if ( node == nullptr )
            return;
        
        solve( node->left, output );
        output.push_back( node->val );
        solve( node->right, output );
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector < int > output;
        solve( root, output );
        return output;
    }
};