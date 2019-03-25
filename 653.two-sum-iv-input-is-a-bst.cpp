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
        bool findTarget(TreeNode* root, int k)
        {
            vector<int> nums;
            inorder(root, nums);
            int l = 0, r = nums.size()-1;
            while (l < r)
            {
                if (nums[l]+nums[r] == k)
                    return true;
                else if (nums[l]+nums[r] < k)
                    l++;
                else if (nums[l]+nums[r] > k)
                    r--;
            }
            return false;
        }

        void inorder(TreeNode* root, vector<int>& nums)
        {
            if (root == NULL)
                return;
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }

};
