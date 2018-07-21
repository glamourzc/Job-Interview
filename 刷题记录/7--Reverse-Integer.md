### [7\. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

Difficulty: **Easy**



Given a 32-bit signed integer, reverse digits of an integer.

**Example 1:**

```
**Input:** 123
**Output:**  321
```

**Example 2:**

```
**Input:** -123
**Output:** -321
```

**Example 3:**

```
**Input:** 120
**Output:** 21
```

**Note:**  
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



#### Solution
```
class Solution {
public:
    int reverse(int x) {
        int rst = 0;
        
        while(x != 0){
            int next_rst = rst * 10 + x % 10;
            x = x / 10;
            //为了判断越界的情况
            if(next_rst/10 != rst) {
                rst  = 0;
                break;
            }
            rst = next_rst;
        }
        return rst;
    }
};
```
