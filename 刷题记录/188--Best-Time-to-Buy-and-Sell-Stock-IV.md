### [188\. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

Difficulty: **Hard**

**思路：这个题还是挺难的，看了一下网上的思路,链接地址：http://blog.csdn.net/linhuanmars/article/details/23236995**
> 这里我们先解释最多可以进行k次交易的算法，然后最多进行两次我们只需要把k取成2即可。
使用“局部最优和全局最优解法”。维护两种量，一个是当前到达第i天可以最多进行j次交易，最好的利润是多少（`global[i][j]`），另一个是当前到达第i天，最多可进行j次交易，并且最后一次交易在当天卖出的最好的利润是多少（`local[i][j]`）。
下面来看递推式，全局的比较简单，`global[i][j]=max(local[i][j],global[i-1][j])`，也就是去当前局部最好的，和过往全局最好的中大的那个（因为最后一次交易如果包含当前天一定在局部最好的里面，否则一定在过往全局最优的里面）。对于局部变量的维护，递推式是`local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)`，也就是看两个量，第一个是全局到i-1天进行j-1次交易，然后加上今天的交易，如果今天是赚钱的话（也就是前面只要j-1次交易，最后一次交易取当前天），第二个量则是取local第i-1天j次交易，然后加上今天的差值（这里因为local[i-1][j]比如包含第i-1天卖出的交易，所以现在变成第i天卖出，并不会增加交易次数，而且这里无论diff是不是大于0都一定要加上，因为否则就不满足local[i][j]必须在最后一天卖出的条件了）。
上面的算法中对于天数需要一次扫描，而每次要对交易次数进行递推式求解，所以时间复杂度是O(n*k)，如果是最多进行两次交易，那么复杂度还是O(n)。空间上只需要维护当天数据皆可以，所以是O(k)，当k=2，则是O(1)。

**另外，在leetcode上，必须判断`k > = prices.size()/2`，不然内存会有问题。开始以为买和卖一次操作是分别一次交易，其实买卖一起算一次交易。**

Say you have an array for which the _i_<sup>th</sup> element is the price of a given stock on day _i_.

Design an algorithm to find the maximum profit. You may complete at most **k** transactions.

**Note:**  
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



#### Solution
```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())return 0;
        int res=0;
        if(k >= prices.size()/2){
            for(int i=0;i<prices.size()-1;i++)
                if(prices[i+1]-prices[i]>0)
                    res+=prices[i+1]-prices[i];
        }else{
            vector<int> global(k+1);
            vector<int> local(k+1);
        
            for(int i=0;i<prices.size()-1;i++){
                int diff = prices[i+1] - prices[i];
                for(int j=k;j>=1;j--){
                    local[j]=max(global[j-1]+max(diff,0),local[j]+diff);
                    global[j]=max(global[j],local[j]);
                }
            }
            res = global[k];
        }
        return res;
    }
};
```
