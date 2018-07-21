### [650\. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/description/)

Difficulty: **Medium**



Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

1.  `Copy All`: You can copy all the characters present on the notepad (partial copy is not allowed).
2.  `Paste`: You can paste the characters which are copied **last time**.

Given a number `n`. You have to get **exactly** `n` 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get `n` 'A'.

**Example 1:**  

```
**Input:** 3
**Output:** 3
**Explanation:**
Intitally, we have one character 'A'.
In step 1, we use **Copy All** operation.
In step 2, we use **Paste** operation to get 'AA'.
In step 3, we use **Paste** operation to get 'AAA'.
```

**Note:**  

1.  The `n` will be in the range [1, 1000].



#### Solution

Language: **C++**

思路：将整个序列划分为等长的小序列，最差的情况是分为n*1的小序列，只能一个一个的粘贴，即n次。不过对于非素数，可以利用其因子进行划分，划分为i份，即f(n)=min(n,i+f(n/i))。
```c++
class Solution {
public:
    int minSteps(int n) {
        if (n == 1)return 0;
        int res = n;
        for (int i = n - 1; i > 1; i--){
            if (n%i == 0)res = min(res, i + minSteps(n / i));
        }
        return res;
    }
};
```
Language:**Python**

正向的动态规划，运行时间好长啊，不知道是不是我写的有问题
```python
 class Solution:
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = list(range(1,n+1))
        res[0] =0
        for i in range(1,n):
            for j in range(2,i+1):
                if (i+1)%j==0:
                    res[i] = min(res[i],j+res[i//j])
        return res[n-1]
```


发现了一种巧妙的解法，将欲求的序列一直分割，知道分到素数为止。
```c++
class Solution {
public:
	int minSteps(int n) {
		int res = 0;
		for (int i = 2; i <= n; ++i) {
			while (n % i == 0) {
				res += i;
				n /= i;
			}
		}
		return res;
	}
};
```
