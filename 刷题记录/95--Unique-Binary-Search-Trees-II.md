### [95\. Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/description/)

Difficulty: **Medium**

**思路：循环递归生成树。需要注意的地方就是，最后拼接树的时候，如果字数为空，不能直接跳出。所以当`end<begin`时，为了方便，加入了`NULL`，但是测试用例有一个n=0，如过期待输出为`[]`，但是实际输出由于有`NULL`，为`[[]]`。所以最后又加了个判断。

Given an integer _n_, generate all structurally unique **BST's** (binary search trees) that store values 1..._n_.

For example,  
Given _n_ = 3, your program should return all 5 unique BST's shown below.

```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```



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
    vector<TreeNode*> generate(int begin,int end) {
        vector<TreeNode*> res;
        if(end<begin){
            res.push_back(NULL);
            return res;
        }
        if(begin==end){
            TreeNode* leaf = new TreeNode(begin);
            res.push_back(leaf);
            return res;
        }
        for(int k=begin ;k<= end;k++){
            
            
            vector<TreeNode*> left =generate(begin,k-1);
            vector<TreeNode*> right =generate(k+1,end);
            
            for(int i =0;i<left.size();i++)
                for(int j =0;j<right.size();j++){
                    TreeNode* root= new TreeNode(k);
                    res.push_back(root);
                    root->left = left[i];
                    root->right = right[j];
                }    
            }
    return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0)return res;
        res = generate(1,n);
        return res;
    }
};
```
