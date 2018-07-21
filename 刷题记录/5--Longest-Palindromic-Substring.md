### [5\. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)

Difficulty: **Medium**



Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

**Example:**

```
**Input:** "babad"

**Output:** "bab"

**Note:** "aba" is also a valid answer.
```

**Example:**

```
**Input:** "cbbd"

**Output:** "bb"
```



#### Solution
```
class Solution {
public:
    string longestPalindrome(string s) {
        int longest=1,tag=0;
        for(float k=0.5;k<s.length();k+=0.5){
        int i=int(ceil(k-1)),j=int(floor(k+1)),len=1,l;
        while(i>=0 && j<s.length() && s.at(i) == s.at(j)){
            len=j-i+1;
            l=i--;
            j++;
        }
        if(len>longest){
            longest=len;
            tag=l;
        }
    }
        return s.substr(tag,longest);
    }
};
```

```python
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ls =''
        longest, left= 1, 0
        for i in s:
            ls = ls + "#" + i
        ls = ls + "#" #for the case 'a'
        print(ls)
        for i in range(1,len(ls)):
            x, y, length, tag  = i-1, i+1, 1, 0
            while (x >= 0) and (y < len(ls)) and (ls[x] == ls[y]):
                tag = x
                length = y - x + 1
                x,y = x-1, y+1
                
            if longest < length:
                longest = length
                left = tag
            
        p =ls[left:left+longest]
        return p.replace("#",'')
def main():
    print(Solution().longestPalindrome('cbbd'))
if __name__ == '__main__':
    main()
```
