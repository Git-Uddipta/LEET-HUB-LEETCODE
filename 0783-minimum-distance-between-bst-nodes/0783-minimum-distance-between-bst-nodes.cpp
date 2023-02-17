/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> pre;
    void preO(TreeNode *root)
    {
        if (!root) return;
        pre.push_back(root->val);
        preO(root->left);
        preO(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {

        preO(root);
        sort(pre.begin(), pre.end());
        int ans = 1e9 + 7;
        for (int i = 0; i < pre.size() - 1; i++) ans = min(ans, pre[i + 1] - pre[i]);
        return ans;
    }
};