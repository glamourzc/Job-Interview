### [392\. Is Subsequence](https://leetcode.com/problems/is-subsequence/description/)

Difficulty: **Medium**



Given a string **s** and a string **t**, check if **s** is subsequence of **t**.

You may assume that there is only lower case English letters in both **s** and **t**. **t** is potentially a very long (length ~= 500,000) string, and **s** is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

**Example 1:**  
**s** = `"abc"`, **t** = `"ahbgdc"`

Return `true`.

**Example 2:**  
**s** = `"axc"`, **t** = `"ahbgdc"`

Return `false`.

**Follow up:**  
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

**思路：**
两个指针遍历，知道指向s的指针到达s的尾。

#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)return true;
        if(t.size() < s.size()) return false;
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;j++;
                if(i==s.size())return true;
            }else{
                j++;
            }
        }
        return false;
    }
};
```
Language: **Python**
```python
class Solution:
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) > len(t):
            return False
        i=j=0
        while i<len(s) and j<len(t):
            if s[i]==t[j]:
                i = i+1
                j = j+1
            else:
                j = j+1
        return i == len(s)
```
