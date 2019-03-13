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
        TreeNode* subtreeWithAllDeepest(TreeNode* root)
        {
            if (root->left == NULL && root->right == NULL)
                return root;
            else if (root->right == NULL)
                return subtreeWithAllDeepest(root->left);
            else if (root->left == NULL)
                return subtreeWithAllDeepest(root->right);
            else
            {
                if (length(root->left) > length(root->right))
                    return subtreeWithAllDeepest(root->left);
                else if (length(root->right) > length(root->left))
                    return subtreeWithAllDeepest(root->right);
                else
                    return root;
            }
                
        }
        
        int length(TreeNode* root)
        {
            if (root->left && root->right)
                return max(length(root->left), length(root->right))+1;
            else if (root->left)
                return length(root->left)+1;
            else if (root->right)
                return length(root->right)+1;
            else
                return 1;

        }
};
