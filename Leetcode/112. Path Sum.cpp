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

    void path ( TreeNode* node, int& sum, int& target, bool& flag ) {

        if ( node == nullptr ||  flag )
            return;

        sum += node->val;

        if ( sum == target && node->left == nullptr && node->right == nullptr ) {
            flag = true;
            return;
        }

        if ( node -> left != nullptr )
            path( node->left, sum, target, flag );

        if ( node -> right != nullptr )
            path( node->right, sum, target, flag );

        sum -= node->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool p = false;
        int sum = 0;
        path( root, sum, targetSum, p);
        return p;
    }
};