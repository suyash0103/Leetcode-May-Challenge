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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root;
        for(int i = 0; i < preorder.size(); i++)
        {
            TreeNode* node = new TreeNode(preorder[i]);
            if(i == 0)
                root = node;
            if(st.empty())
            {
                st.push(node);
            }
            else
            {
                if(node->val < st.top()->val)
                {
                    st.top()->left = node;
                    st.push(node);
                }
                else
                {
                    TreeNode* curr;
                    while(!st.empty() && node->val > st.top()->val)
                    {
                        curr = st.top();
                        st.pop();
                    }
                    curr->right = node;
                    st.push(node);
                }
            }
        }
        return root;
    }
};