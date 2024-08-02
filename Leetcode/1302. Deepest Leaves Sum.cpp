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

    void solve ( TreeNode* node, int& sum, int level, int& deepest ) {
        if ( node == nullptr )
            return;
        
        if ( level > deepest ) {
            sum = node->val;
            deepest = level;
        } else if ( level == deepest ) {
            sum += node->val;
        }

        solve( node->left, sum, level + 1, deepest );
        solve( node->right, sum, level + 1, deepest );

    }

    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, deepest = 0;
        solve( root, sum, 0, deepest );
        return sum;
    }
};