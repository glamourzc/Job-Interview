### [32\. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/description/)

Difficulty: **Hard**

**思路：先把能配上对的表示出来，然后进行个统计“

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

For `"(()"`, the longest valid parentheses substring is `"()"`, which has length = 2.

Another example is `")()())"`, where the longest valid parentheses substring is `"()()"`, which has length = 4.



#### Solution
```
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> tag(s.length(),-2);
        for(int i=0;i<s.length();i++){
            if(s.at(i) == '(')tag[i]=-1;
            else{
                for(int j=i-1;j>=0;j--){
                    if(tag[j]==-1){
                        tag[i]=j;
                        tag[j]=i;
                        break;
                    }
                }
            }
        }
        int res=0;
        vector<int> tag2(s.length()+1,0);
        for(int i=1;i<=s.length();i++){
            if(tag[i-1]>=0){
                tag2[i]=tag2[i-1]+1;
                res = res > tag2[i] ? res : tag2[i];
            }else{tag2[i]==0;}
        }
        return res;
    }
};
```
