### [115\. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/)

Difficulty: **Hard**

**思路：动态规划，主要公式为 `num[i][j] = num[i - 1][j - 1] + num[i][j - 1]`，找一下初始状态**

**小知识：初始化一个`m*n`的vector二维数组，可以使用`  vector<vector<int>> num(m, vector<int>(n))`**

Given a string **S** and a string **T**, count the number of distinct subsequences of **S** which equals **T**.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

Here is an example:  
**S** = `"rabbbit"`, **T** = `"rabbit"`

Return `3`.



#### Solution
```
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length())
            return 0;
        int m = t.length();
        int n = s.length();
        vector<vector<int>> num(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++)
            num[0][i] = 1;
        for (int i = 1; i<=m; i++)
        for (int j = 1; j<=n; j++){
            if (s.at(j - 1) == t.at(i - 1)){
                num[i][j] = num[i - 1][j - 1] + num[i][j - 1];
            }
            else{
                num[i][j] = num[i][j - 1];
            }
        }
        return num[m][n];
    }
};
```
