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

    void solve ( TreeNode* node, int target, long long& sum, int& count ) {

        if ( node == nullptr )
            return;
        
        sum += node -> val;

        if ( sum == target )
            count++;

        solve( node->left, target, sum, count );
        solve( node->right, target, sum, count );

        sum -= node->val;
    }

    void rootAux ( TreeNode* root, int target, long long& sum, int& count ) {
        if ( root == nullptr )
            return;
        
        solve( root, target, sum, count );
        rootAux( root->left, target, sum, count );
        rootAux( root->right, target, sum, count );
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        long long sum = 0;
        rootAux( root, targetSum, sum, count );
        return count;
    }
};