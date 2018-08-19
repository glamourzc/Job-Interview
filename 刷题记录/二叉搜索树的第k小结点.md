## 题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

## Solution
> 中序遍历，不过如果使用递归的话难以跳出，所以使用了栈进行存储
```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        stack<TreeNode*> s;
        if(k<1)return nullptr;
        while(pRoot || !s.empty()){
            while(pRoot){
                s.push(pRoot);
                pRoot = pRoot->left;
            }
            k--;
            pRoot = s.top();
            if(k==0)return pRoot;
            s.pop();
            pRoot = pRoot->right;
        }
        return nullptr;
    }
};
```


> Python Version
```python
class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        # write code here
        stack=[]
        if k<1:
            return None
        while pRoot or len(stack)>0:
            while pRoot:
                stack.append(pRoot)
                pRoot = pRoot.left
            k -= 1
            pRoot = stack.pop()
            if not k:
                return pRoot
            pRoot = pRoot.right
        return None
```