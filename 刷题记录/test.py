# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        a = {}
        for c in s:
            if a.__contains__(c):
                a[c] += 1
            else:
                a[c] = 1
        for i in range(0,len(s)):
            if a[s[i]] == 1:
                return i
        return -1
x = Solution()
s = "google"
print(x.FirstNotRepeatingChar(s))