#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> res(input.begin(),input.begin()+k);
        return res;
    }
};
int main(){
    vector<int> input{4,5,1,6,2,7,3,8};
    Solution x;
    vector<int> res = x.GetLeastNumbers_Solution(input,4);
    for(int i:res)
        cout<<i<<endl;
    return 0;
}