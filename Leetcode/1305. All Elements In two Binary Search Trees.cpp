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

    void add ( vector< int >& elements, TreeNode* node ) {
        if ( node == nullptr )
            return;
        
        elements.push_back( node->val );
        add( elements, node->left );
        add( elements, node->right );
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector< int > elements;
        add( elements, root1 );
        add( elements, root2 );
        sort(elements.begin(), elements.end());
        return elements;
    }
};