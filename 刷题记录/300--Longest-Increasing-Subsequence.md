### [300\. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/)

Difficulty: **Medium**



Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,  
Given `[10, 9, 2, 5, 3, 7, 101, 18]`,  
The longest increasing subsequence is `[2, 3, 7, 101]`, therefore the length is `4`. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(_n<sup>2</sup>_) complexity.

**Follow up:** Could you improve it to O(_n_ log _n_) time complexity?



#### Solution
##### c++:最常规的方法，复杂度为O(n^2)。
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<int> len(nums.size());
        int m = 1;
        for(int i=0;i<nums.size();i++){
            len[i]=1;
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    len[i] = max(len[i],len[j]+1);
                    m = max(m,len[i]);
                }
            }
        }
        return m;
    }
};
```
##### python:
```
class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        f=[1] * len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[i]>nums[j]:
                    f[i]=max(f[i],f[j]+1)
        return max(f)
```
