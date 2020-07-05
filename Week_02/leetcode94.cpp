/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        TreeNode* curr = root;
        TreeNode* pre;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                res.push_back(curr->val);
                curr = curr->right; // move to next right node
            } else { // has a left subtree
                pre = curr->left;
                while (pre->right != nullptr) { // find rightmost
                    pre = pre->right;
                }
                pre->right = curr; // put cur after the pre node
                TreeNode* temp = curr; // store cur node
                curr = curr->left; // move cur to the top of the new tree
                temp->left = nullptr; // original cur left be null, avoid infinite loops
            }
        }
        return res;
    }
};