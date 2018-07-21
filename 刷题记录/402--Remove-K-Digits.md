### [402\. Remove K Digits](https://leetcode.com/problems/remove-k-digits/description/)

Difficulty: **Medium**



Given a non-negative integer _num_ represented as a string, remove _k_ digits from the number so that the new number is the smallest possible.

**Note:**  

*   The length of _num_ is less than 10002 and will be ≥ _k_.
*   The given _num_ does not contain any leading zero.

**Example 1:**

```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

**Example 2:**

```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200\. Note that the output must not contain leading zeroes.
```

**Example 3:**

```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```



#### Solution
```
//若num.size() == k，则直接返回“0”；
//剩下的逻辑就是如果前一个比后一个大，则删除前一个。如果一直没出现，则删去最后一个。
//最后去掉前面的“0”。
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        if(num.size() == k){
            res = "0";
            return res;
        }
        while(k--){
            bool tag = false;
            for(int i=0;i<num.size()-1;i++){
                if(num[i]>num[i+1]){
                    num.erase(i,1);
                    tag = true;
                    break;
                }
            }
            if(!tag)num.erase(num.size()-1,1);
        }
        while (!num.empty() && num[0]=='0')num.erase(num.begin());
        return num;
    }
};
```
##### c++2:
```
//这种方法时间复杂度比较低。
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};
```
##### python:
```
class Solution:
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        res=""
        keep = len(num)-k
        for c in num:
            while k and len(res) and res[-1] > c:
                res = res[:-1]
                k -= 1
            res += c
        res = res[:keep]
        res = res.lstrip('0')
        return len(res) and res or "0" 

```
