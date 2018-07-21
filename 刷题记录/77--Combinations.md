### [77\. Combinations](https://leetcode.com/problems/combinations/description/)

Difficulty: **Medium**

**即找出所有的子集，从尾部依次枚举，相当于深度优先**

Given two integers _n_ and _k_, return all possible combinations of _k_ numbers out of 1 ... _n_.

**Example:**

```
**Input:** n = 4, k = 2
**Output:**
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```



#### Solution
##### c++:
```c++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> stack;
        for(int i = 1;i <= k;i++){
            stack.push_back(i);
        }
        res.push_back(stack);
        while(1){
            while(stack.size()>0 && stack.back() == n+stack.size()-k)stack.pop_back();
            //这句话最关键，第i个的最大值不超过n+i-k
            if(stack.empty())break;
            ++stack[stack.size()-1];
            while(stack.size()<k)stack.push_back(stack[stack.size()-1]+1);
            res.push_back(stack);
        }
        return res;
    }
};
```
##### python:
```python
# -*- coding=utf-8 -*-
import copy
class Solution:
    def combine(self,n,k):
        stack = [i for i in range(1,k+1)]
        self.res = []
        #self.res.append(copy.deepcopy(stack))，用下面这种形式
        self.res.append(stack[:])
        while True:
            while len(stack)>0 and stack[-1]==n+len(stack)-k:
                #stack = stack[:-1]，用下面这种形式
                stack.pop()
            if(len(stack)==0):
                break
            stack[-1] = stack[-1]+1
            while len(stack)<k:
                stack.append(stack[-1]+1)
            #self.res.append(copy.deepcopy(stack))
            self.res.append(stack[:])
        return self.res 
res = Solution().combine(4,2)
print(res)
```
##### python2
```python
# -*- coding=utf-8 -*-
import copy
class Solution:
    def combine(self,n,k):
        self.res = []
        temp = []
        self.dfs(n,k,1,0,temp)
        return self.res
    
    def dfs(self,n,k,m,p,temp):
        if k == p:
            #self.res.append(copy.deepcopy(temp))
            #下面这种形式相当于深度复制
            self.res.append(temp[:])
            return
        for i in range(m,n+1):
            temp.append(i)
            self.dfs(n,k,i+1,p+1,temp)
            temp.pop()
res = Solution().combine(4,2)
print(res)
```
