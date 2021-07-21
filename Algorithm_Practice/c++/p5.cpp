#include <iostream>
#include <algorithm>
#define SWAP(x,y) {int t; t=x; x=y; y=t;}; //c++에서 define으로 매크로 정하는 문법 주의
using namespace std;
//boj 10804 성공

int main(){
	int a,b;
	int arr[21];
	int j,k;
	for(int i=1; i<=20; i++){
		arr[i]=i;
	}
	
	for(int i=0; i<10; i++){
		cin>>a>>b;
		
		//reverse로 간단히 할 수도 있고, 매크로 이용해서 swap으로 구현할 수도 있다.
		//reverse(arr+a, arr+b+1);
		for(j=a;j<=(a+b)/2; j++){
			SWAP(arr[j],arr[(a+b)-j]);
		}
	}
		for(int i=1; i<=20; i++) cout<< arr[i]<<" ";
		//cout<<"\n";
	
}
