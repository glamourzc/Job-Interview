### [64\. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/)

Difficulty: **Medium**



Given a _m_ x _n_ grid filled with non-negative numbers, find a path from top left to bottom right which _minimizes_ the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example 1:**  

```
[[1,3,1],
 [1,5,1],
 [4,2,1]]
```

Given the above grid map, return `7`. Because the path 1→3→1→1→1 minimizes the sum.

#### Solution
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> min(grid[0].size() + 1, 10000);
        min[1] = 0;
        for (int i = 0; i<grid.size(); i++)
        for (int j = 0; j<grid[0].size(); j++){
            min[j + 1] = (min[j] + grid[i][j])<(min[j + 1] + grid[i][j]) ? min[j] + grid[i][j] : min[j + 1] + grid[i][j];
        }
        return min[grid[0].size()];
    }
};
```
