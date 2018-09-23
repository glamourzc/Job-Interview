## 题目描述
![mark](http://omwiezyrk.bkt.clouddn.com/blog/20180921/155722712.png)
```c++
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> res;
    while(n != 0){
    	if(n%2 == 0){
    		res.push_back(3); 
        	n = n/2 -1;
   		}
    	else{
    		res.push_back(2); 
        	n = (n-1)/2;
    	}
    }
	for(auto i=res.rbegin();i<res.rend();i++){
    	cout<<*i;
    }
    cout<<endl;
	return 0;
}
```