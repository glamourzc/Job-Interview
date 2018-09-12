#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdio.h>
using namespace std;

#define random(a,b) (rand()%(b-a+1)+a)

int main(){
  float money,minMoney,maxMoney;
  int n;
  cin>>money>>n>>minMoney>>maxMoney;
  vector<float> res;
  
  res.push_back(1.00);
  int y = money - 1.00;
  srand((unsigned)time(NULL));
  int base = minMoney * (n-1);
  float a = y - base;
  
  for(int i=0;i<n-3;i++){
    int k =maxMoney - minMoney;
    int r = random(0,k);
    if(r<a){
      res.push_back(minMoney + r);
      a -= r;
    }else{
    	r = random(0,r);
      	res.push_back(minMoney + r);
      	a -= r;
    }
  }
  res.push_back(a);
  int tmpM,maxM,maxP = 0;
  for(int i=0;i<n;i++){
    maxP = maxM<res[i]?i:maxP;
    tmpM = money - res[i];
  	printf("第%d个人抢到的红包金额为%02f，红包剩余金额为%02f\n",i+1,res[i],tmpM);
  }
  printf("抢到红包金额最多的是%d\n",maxP);
  return 0;
}