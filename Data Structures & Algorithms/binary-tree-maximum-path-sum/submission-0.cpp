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

    int maxSum = INT_MIN;

    int dfs(TreeNode *root)    {
        if(root == NULL)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        maxSum = max(maxSum, left + root -> val + right);

        return root -> val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

// BRUTE FORCE - Try every node as the highest/middle node
// For every node, calculate the maximum path sum from its left
// and right subtree and check the path passing through that node.
// Repeat this for every node in the tree.
// Since subtree heights/path sums can be recalculated many times,
// the same nodes are processed repeatedly.
// Time Complexity: O(N^2) in the worst case     Space Complexity: O(H)

// OPTIMAL - DFS + Global Maximum
// Recursively calculate the maximum one-sided path from left and right.
// Ignore negative paths using max(0, left/right).
// left + node + right gives the best path passing through the current node.
// Update the global maximum using this path.
// Return node + max(left, right) because only one branch can continue
// to the parent.
// Time Complexity: O(N)     Space Complexity: O(H)