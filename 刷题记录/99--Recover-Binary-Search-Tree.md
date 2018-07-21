### [99\. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/)

Difficulty: **Hard**



Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

**Note:**  
A solution using O(_n_) space is pretty straight forward. Could you devise a constant space solution?

#### Solution
**最简单的方式就是先中序遍历一次，然后排序，再重新赋值一次**
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
    vector<int> res;
    int i=0;
    bool tag=false;
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(res.begin(),res.end());
        tag=true;
        inorder(root);        
    }
    
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(tag){
            root->val = res[i];
            i++;
        }else{
            res.push_back(root->val); 
        }
        inorder(root->right);
    }
};
```

**上面写的中序遍历了两次，有点笨，下面这个只需要中序遍历一次**
```
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
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> list;
        vector<int> vals;
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = vals[i];
        }
    }
    void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
        if (!root) return;
        inorder(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, list, vals);
    }
};
```
如果想让
