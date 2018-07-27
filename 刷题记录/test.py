# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        odd =[]
        even = []
        for i in array:
            if i%2 != 0:
                odd.append(i)
            else:
                even.append(i)
        return odd + even
x = Solution()
array = list(range(1,8))
print(x.reOrderArray(array))