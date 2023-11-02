#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

//재귀
//k에 얼마를 곱해야하는가
//5제곱 -> 2제곱*2제곱*1제곱 - n의 범위가 크기 때문에 2제곱씩 잘라서 곱함.
long long recur(long long num, long long p){
  if(num==1){
    return p;
  }
  long long result = recur(num/2, p);
  result = (result*result)%1000000007; 
  if(num%2==1)
    result = (result*p)%1000000007; //num이 홀수인 경우 p를 한 번 곱해줘야함
  return result;
}

int main(int argc, char** argv)
{
  
  long long k, p, n;

  cin>>k>>p>>n;
  if(p==1){
    cout<<k;
    return 0;
  }
  
  k *= recur(10*n, p);
  k %= 1000000007;
  cout<<k;
  
  return 0;
}