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

    void solve (vector<int>& tree, TreeNode* node ) {
        if ( node == nullptr ){
            tree.push_back(-10);
            return;
        }
        
        tree.push_back( node->val );
        solve( tree, node->left );
        solve( tree, node->right );
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector < int > t1, t2;
        solve( t1, p );
        solve( t2, q );
        return t1 == t2;
    }
};