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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root != NULL)    {
            if(p -> val > root -> val && q -> val > root -> val)
                root = root -> right;
            
            else if(p -> val < root -> val && q -> val < root -> val)
                root = root -> left;

            else
                return root;
        }
        return NULL;
    }
};

// BRUTE FORCE - Store paths from root to p and q
// Find the path from root to p and root to q using DFS.
// Compare both paths and find the last common node.
// That node is the Lowest Common Ancestor.
// Time Complexity: O(N)     Space Complexity: O(N) for storing the paths

// OPTIMAL - Use BST property
// Compare p and q with the current root.
// If both are smaller, move to the left subtree.
// If both are larger, move to the right subtree.
// Otherwise, p and q are on different sides or one is the root,
// so the current root is the Lowest Common Ancestor.
// Time Complexity: O(H), where H is the height of the tree    Space Complexity: O(1)

/*
    bool findpath( TreeNode *root, TreeNode *target, vector<TreeNode *>&path)   {
        if(root == NULL)
            return false;
        
        path.push_back(root);

        if(root == target)
            return true;

        if(findpath(root->right , target, path) || findpath(root -> left, target, path))
            return true;
        
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;

        findpath(root, p, pathP);
        findpath(root, q, pathQ);

        TreeNode *lca = NULL ;

        int i =0;
        while(i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            lca = pathP[i];
            i++;
        }

        return lca;
*/