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

    unordered_map<int,int> mp;

    TreeNode* build(vector<int> &preorder, int &preindex, int inStart, int inEnd)   {

        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preindex]);
        preindex++;

        int inIndex = mp[root->val];

        root -> left = build(preorder, preindex, inStart, inIndex-1);
        root -> right = build(preorder, preindex, inIndex+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preindex= 0;

        return build(preorder, preindex, 0, inorder.size()-1);
        
    }
};

// BRUTE FORCE - Linear Search in Inorder
// Preorder ka first element current root hota hai.
// Inorder mein root ko linear search karke uska index find karo.
// Root ke left wale elements left subtree mein aur right wale
// elements right subtree mein jaayenge.
// Recursively same process repeat karo.
// Time Complexity: O(N^2) in the worst case     Space Complexity: O(N)

// OPTIMAL - Hash Map + Recursion
// Preorder ka first element current root hota hai.
// Hash map mein inorder values ke indexes store karte hain,
// so root ka inorder index O(1) mein mil jaata hai.
// Root ke left aur right parts ko recursively build karte hain.
// Time Complexity: O(N)     Space Complexity: O(N)