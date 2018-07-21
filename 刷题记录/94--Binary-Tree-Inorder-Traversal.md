### [94\. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

Difficulty: **Medium**

**思路：使用栈代替递归**


Given a binary tree, return the _inorder_ traversal of its nodes' values.

For example:  
Given binary tree `[1,null,2,3]`,  

```
   1
    \
     2
    /
   3
```

return `[1,3,2]`.

**Note:** Recursive solution is trivial, could you do it iteratively?



#### Solution
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> temp;
        TreeNode * cur = root;
        while (cur || !temp.empty()){
            while (cur){
                temp.push(cur);
                cur = cur->left;
            }
​
            cur = temp.top();
            res.push_back(cur->val);
            temp.pop();
            cur = cur->right;
        }
        return res;
    }
};
```
