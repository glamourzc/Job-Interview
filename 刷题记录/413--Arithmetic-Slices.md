### [413\. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/description/)

Difficulty: **Medium**



A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

```
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9```

The following sequence is not arithmetic.

```
1, 1, 2, 5, 7```

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:  
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

**Example:**

```
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
```

**思路：** 枚举前三个，然后向后延长

#### Solution

Language: **C++**

```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0,n = A.size();
        for(int i=0;i<n-2;i++){
            int diff = A[i+1] - A[i];
            for(int j = i+2;j<n;j++){
                if(A[j] - A[j-1] == diff)res++;
                else break;
            }
        }
        return res;
    }
};
```
Lauguage: **Python**
```python
class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(A)-2):
            diff = A[i+1] - A[i]
            for j in range(i+2,len(A)):
                if A[j] - A[j-1] == diff:
                    res+=1
                else:
                    break
        return res
```
