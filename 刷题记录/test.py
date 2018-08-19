# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        return size and [max(num[i:i+size]) for i in range(len(num)-size+1)] or []
x = Solution()
num = [2,3,4,2,6,2,5,1]
print(x.maxInWindows(num,0))