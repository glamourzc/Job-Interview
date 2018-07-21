### [476\. Number Complement](https://leetcode.com/problems/number-complement/description/)

Difficulty: **Easy**



Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

**Note:**  

1.  The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2.  You could assume no leading zero bit in the integer’s binary representation.

**Example 1:**  

```
**Input:** 5
**Output:** 2
**Explanation:** The binary representation of 5 is 101 (no leading zero bits), and its complement is 010\. So you need to output 2.
```

**Example 2:**  

```
**Input:** 1
**Output:** 0
**Explanation:** The binary representation of 1 is 1 (no leading zero bits), and its complement is 0\. So you need to output 0.
```



#### Solution

Language: **C++**

```c++
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num)mask <<= 1;//计算num前面有多少个0
        return ~mask & ~num;
    }
};
```
Language：**Python**
```python
class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        return int(''.join(list(map(lambda x:'1' if x=='0' else '0',bin(num)[2:]))),2)
        #bin()，求二进制，输出str，格式为0b___，没有前面的补0
        #map(function,itertor,...)，取反
```
