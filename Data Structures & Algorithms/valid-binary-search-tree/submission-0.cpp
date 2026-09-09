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

    bool check(TreeNode* root, long long minVal, long long maxVal)  {
        if(root == NULL)
            return true;

        if(root -> val <= minVal || root -> val >= maxVal)
            return false;

        return check(root-> left, minVal, root->val) &&
               check(root-> right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

// BRUTE FORCE
// For every node, find the maximum value in its left subtree
// and the minimum value in its right subtree.
// If leftMax >= current value or rightMin <= current value,
// the tree is invalid.
// Recursively validate the left and right subtrees.
// Time Complexity: O(N^2) in the worst case       Space Complexity: O(H)

// OPTIMAL - DFS with valid range
// Maintain the minimum and maximum values allowed for each node.
// For the left subtree, the current node becomes the upper limit.
// For the right subtree, the current node becomes the lower limit.
// If a node falls outside its allowed range, return false.
// Time Complexity: O(N)     Space Complexity: O(H)
