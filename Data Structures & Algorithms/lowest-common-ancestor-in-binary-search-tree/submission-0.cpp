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