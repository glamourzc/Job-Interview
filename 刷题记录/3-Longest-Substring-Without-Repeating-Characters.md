### [3\. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

Difficulty: **Medium**



Given a string, find the length of the **longest substring** without repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3\. Note that the answer must be a **substring**, `"pwke"` is a _subsequence_ and not a substring.



#### Solution
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<1)return 0;
        int asc[129]={0};
        int res=1,tag=1,max=1;
        //memset(asc,0,128*sizeof(int));
        for(int i=0;i+max<s.length();){
            char tempi=s.at(i);
            asc[int(tempi)]=i+1;
            for(int j=tag;j<s.length();j++){
                char tempj=s.at(j);
                if(asc[int(tempj)]<i+1){
                    asc[int(tempj)]=j+1;
                    res++;
                }else{
                    i=asc[int(tempj)];
                    asc[int(tempj)]=j+1;
                    if(max<res)max=res;
                    tag=j+1;
                    res=j-i+1;
                    break;
                }  
            }
        }
        return max;          
    }
};
```
