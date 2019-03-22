/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
        {
            return helper(preorder, inorder, 0, 0, preorder.size()-1);
        }

        TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int prestart, int instart, int inend)
        {
            if (prestart >= preorder.size())
                return NULL;
            if (instart > inend)
                return NULL;
            TreeNode* root = new TreeNode(preorder[prestart]);
            auto root_pos = std::find(inorder.begin(), inorder.end(), preorder[prestart]);
            int inpos = std::distance(inorder.begin(), root_pos);
            root->left = helper(preorder, inorder, prestart+1, instart, inpos-1);
            root->right = helper(preorder, inorder, prestart+1+inpos-instart, inpos+1, inend);
            return root;
        
        }
};
