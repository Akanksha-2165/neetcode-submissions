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
    int answer;

    void inorder(TreeNode *root, int &n) {
        if(root == NULL)
            return ;

        inorder(root-> left, n);
        n--;

        if(n==0)  {  
            answer = root->val;
            return;
        }

        inorder(root->right, n);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;

    }
};



/*
void inorder(TreeNode *node, vector<int> &values)   {
        if(node == NULL)
            return ;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        inorder(root, values);
        return values[k-1];
*/